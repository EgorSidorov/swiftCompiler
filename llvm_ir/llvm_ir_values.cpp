#include "llvm_ir_generator.h"
#include <cctype>
#include <iostream>
#include "vector"

std::list<value_t*> llvm_ir_generator::GetValues(){
    std::list<value_t*> values;
    for(auto& iter_stack : values_stack){
        for(auto& iter_value : iter_stack)
            values.push_back(&iter_value);
    }
    return values;
}

bool llvm_ir_generator::AddMass(std::string t_name, value_t_type t_type, int count){
    for(auto iter : GetValues()){
        if(iter->t_name == t_name)
            return false;
    }
    value_t new_value;
    new_value.t_name = t_name;
    new_value.t_type = value_t_type::MASS;
    new_value.t_source_number = std::to_string(lastNumber);
    new_value.t_type2 = t_type;
    lastNumber++;
    new_value.isInitialized = false;
    new_value.numberVariable = count;
    values_stack.back().push_back(new_value);
    //values_stack.top().push_back(new_value);
    addProgram("\n%"+new_value.t_source_number+" = alloca [" +std::to_string(count)+" x "+ get_value_t_type_name(t_type) + "], align " + std::to_string(get_value_t_byte_size(t_type)));
    std::cout<<"add mass variable:"+new_value.t_name+" source number:"+new_value.t_source_number+"\n";
    return true;
}

bool llvm_ir_generator::InitMass(std::string t_name,std::string number,std::string value)
{
    bool return_value = false;
    value_t* initialize_value = nullptr;
    for(auto iter : GetValues()){
        if(iter->t_name == t_name){
            initialize_value = iter;
            return_value = true;
        }
    }
    if(!return_value)
        return false;

    initialize_value->isInitialized = true;
    std::string type_name = get_value_t_type_name(initialize_value->t_type2);
    std::string byte_size = std::to_string(get_value_t_byte_size(initialize_value->t_type2));
    std::string count_elem = std::to_string(initialize_value->numberVariable);
    std::string number_str = number;
    std::string source_number = initialize_value->t_source_number;
    //if(value.length() == 1 || !std::isdigit(value.at(1)))
    if(!std::isdigit(value.at(0)) && value.at(0) != '%'){
        InitializeVariable(value);
        for(auto iter : GetValues()){
            if(iter->t_name == value){
                value = "%"+std::to_string(iter->numberVariable);

            }
        }
        //addProgram("\nstore " + type_name + " " + lastVariable() + ", " + type_name + "* %"+initialize_value->t_source_number +", align "+byte_size);
       //value.insert(0,"%");
    }
    lastNumber++;
    addProgram("\n"+lastVariable() + " = getelementptr inbounds ["+count_elem+ " x "+type_name+"], ["+count_elem+ " x "+type_name+"]* %"+source_number+", i64 0, i32 "+number_str);
    addProgram("\nstore " + type_name + " " + value + ", " + type_name + "* "+lastVariable() +", align "+byte_size);
    //InitializeVariable(t_name);
    return return_value;
}

std::string llvm_ir_generator::GetMassElem(std::string t_name, std::string number, value_t_type& outputttype){
    bool return_value = false;
    value_t* initialize_value = nullptr;
    for(auto iter : GetValues()){
        if(iter->t_name == t_name){
            initialize_value = iter;
            return_value = true;
        }
    }
    if(!return_value)
        return false;

    initialize_value->isInitialized = true;
    outputttype = initialize_value->t_type2;
    std::string type_name = get_value_t_type_name(initialize_value->t_type2);
    std::string byte_size = std::to_string(get_value_t_byte_size(initialize_value->t_type2));
    std::string count_elem = std::to_string(initialize_value->numberVariable);
    std::string number_str = number;
    std::string source_number = initialize_value->t_source_number;
    //if(value.length() == 1 || !std::isdigit(value.at(1)))
    lastNumber++;
    addProgram("\n"+lastVariable() + " = getelementptr inbounds ["+count_elem+ " x "+type_name+"], ["+count_elem+ " x "+type_name+"]* %"+source_number+", i64 0, i32 "+number_str);
    addProgram("\n%"+std::to_string(lastNumber)+" = load " + type_name + ", " + type_name + "* "+lastVariable() +", align "+byte_size);
    lastNumber++;
    int numbermasselem = lastNumber;
    std::string valuemasselem = std::to_string(lastNumber-1);
    AddVariable("masselem"+std::to_string(numbermasselem), initialize_value->t_type2);
    InitializeVariable("masselem"+std::to_string(numbermasselem),"%"+valuemasselem);
    return "masselem"+std::to_string(numbermasselem);
}

bool llvm_ir_generator::AddVariable(std::string t_name, value_t_type t_type){
    for(auto iter : GetValues()){
        if(iter->t_name == t_name)
            return false;
    }
    value_t new_value;
    new_value.t_name = t_name;
    new_value.t_type = t_type;
    new_value.t_source_number = std::to_string(lastNumber);
    lastNumber++;
    new_value.isInitialized = false;
    new_value.numberVariable = -1;
    values_stack.back().push_back(new_value);
    //values_stack.top().push_back(new_value);
    if(t_type != value_t_type::STRING)
        addProgram("\n%"+new_value.t_source_number+" = alloca " + get_value_t_type_name(t_type) + ", align " + std::to_string(get_value_t_byte_size(t_type)));
    std::cout<<"add variable:"+new_value.t_name+" source number:"+new_value.t_source_number+"\n";
    return true;
}

void llvm_ir_generator::lifetime_string_start(std::string variable){
    bool find = false;
    value_t var;
    for(auto iter : GetValues()){
        if(iter->t_name == variable){
            var = *iter;
            find = true;
            break;
        }
    }
    if(find){
        lifetime_string_end(variable);
    } else {

       //values_stack.top().push_back(var);
    }
    addProgram("\n%"+std::to_string(lastNumber) + " = bitcast i8** %" + variable + " to i8*");
    var.numberVariable = lastNumber;
    addProgram("\ncall void @llvm.lifetime.start.p0i8(i64 8, i8* nonnull %" + std::to_string(lastNumber) + ") nounwind");
    lastNumber++;
}

void llvm_ir_generator::lifetime_string_end(std::string variable){
    /*bool find = false;
    value_t var;
    for(auto iter : values){
        if(iter.t_name == variable){
            var = iter;
            find = true;
            break;
        }
    }
    if(!find)
        return;
    addProgram("call void @llvm.lifetime.end.p0i8(i64 8, i8* nonnull %"+std::to_string(var.numberVariable)+") nounwind");
    values_lifetime.remove(var);*/
}

void llvm_ir_generator::end_all_lifetimes(){
    for(auto iter : values_lifetime)
        lifetime_string_end(iter.t_name);
}

bool llvm_ir_generator::InitializeVariable(std::string t_name)
{
    bool return_value = false;
    value_t* initialize_value;
    for(auto iter : GetValues()){
        if(iter->t_name == t_name){
            initialize_value = iter;
            return_value = true;
        }
    }
    if(!return_value)
        return false;

    addProgram("\n%"+std::to_string(lastNumber)+" = load " + get_value_t_type_name(initialize_value->t_type) +","+get_value_t_type_name(initialize_value->t_type)+"* %" + initialize_value->t_source_number +", align " + std::to_string(get_value_t_byte_size(initialize_value->t_type)));
    //initialize_value->isInitialized = true;
    initialize_value->numberVariable = lastNumber;
    lastNumber++;
    return return_value;
}

void llvm_ir_generator::InitializeStringConst(std::string t_name, std::string value){
    int value_length = value.length();
    while(value.find("\n") != std::string::npos){
        int index = value.find("\n");
        value.replace(index, 1, "\\0A");
    }
    value_t* initialize_value = NULL;
    bool find = false;
    for(auto iter : GetValues()){
        if(iter->t_name == t_name){
            initialize_value = iter;
            find = true;
            break;
        }
    }
    if(!find)
        return;
    program.insert(0,"@"+initialize_value->t_source_number +std::to_string(lastNumber)+" = private unnamed_addr constant [" + std::to_string(value_length+1) + " x i8] c\"" + value + "\\00\", align 1\n");
    initialize_value->numberVariable = lastNumber;
    addProgram("\n%"+std::to_string(lastNumber)+" = getelementptr [" + std::to_string(value_length+1) + " x i8],[" + std::to_string(value_length+1) + " x i8]* @"+t_name +std::to_string(lastNumber) + " , i32 0, i64 0");
    lastNumber++;
}

bool llvm_ir_generator::InitializeVariable(std::string t_name,std::string value)
{
    bool return_value = false;
    value_t* initialize_value = nullptr;
    for(auto iter : GetValues()){
        if(iter->t_name == t_name){
            initialize_value = iter;
            return_value = true;
        }
    }
    if(!return_value)
        return false;

    //std::string init_name = t_name;
    //if(initialize_value->isInitialized){
        //if(initialize_value->numberVariable != -1)
        //    init_name = std::to_string(initialize_value->numberVariable);
    //} else {
    //    initialize_value->isInitialized = true;
    //}
    initialize_value->isInitialized = true;
    std::string type_name = get_value_t_type_name(initialize_value->t_type);
    std::string byte_size = std::to_string(get_value_t_byte_size(initialize_value->t_type));
    //if(value.length() == 1 || !std::isdigit(value.at(1)))
    if(!std::isdigit(value.at(0)) && value.at(0) != '%'){
        InitializeVariable(value);
        addProgram("\nstore " + type_name + " " + lastVariable() + ", " + type_name + "* %"+initialize_value->t_source_number +", align "+byte_size);
       //value.insert(0,"%");
    }
    else if(value.find("result") == 1){
        InitializeVariable(value);
        addProgram("\nstore " + type_name + " " + lastVariable() + ", " + type_name + "* %"+initialize_value->t_source_number +", align "+byte_size);
    } else
        addProgram("\nstore " + type_name + " " + value + ", " + type_name + "* %"+initialize_value->t_source_number +", align "+byte_size);
    InitializeVariable(t_name);
    return return_value;
}

bool llvm_ir_generator::OperationVariable(value_op_type valueoptype, value_t_type& ifftype, std::string variable1, std::string variable2)
{
    std::cout<<"variable1 "<<variable1<<" variable2 "<<variable2<<"\n";
    for(auto iter : GetValues()){
        std::cout<<iter->t_name<<",";
    }
    std::cout<<"\n";
    bool return_value1 = false;
    std::string value1;
    std::string value2;
    ifftype = value_t_type::INT;
    if(std::isdigit(variable1.at(0))){
        return_value1 = true;
        if(variable1.find(".") != std::string::npos){
            ifftype = value_t_type::DOUBLE;
        } //else if(valuettype == value_t_type::DOUBLE){
            /*addProgram(std::string("\n%") + std::to_string(lastNumber) + std::string(" = alloca i32, align 4"));
            lastNumber++;
            addProgram(std::string("\n%") + std::to_string(lastNumber) + std::string(" = load i32 ")+variable1+ std::string(", i32* ") + std::string("%") + std::to_string(lastNumber-1) + std::string(", align 4"));
            lastNumber++;
            addProgram(std::string("\n%") + std::to_string(lastNumber) + std::string(" = sitofp i32 ") + std::string("%") + std::to_string(lastNumber-1) + std::string(" to double"));
            lastNumber++;*/
            //variable1.append(".0");
        //}
        value1 = variable1;
    } else {
        InitializeVariable(variable1);
        //variable1.insert(0,"%");
    }
    bool return_value2 = false;
    if(std::isdigit(variable2.at(0))){
        return_value2 = true;
        if(variable2.find(".") != std::string::npos)
            ifftype = value_t_type::DOUBLE;
        value2 = variable2;
    } else{
        InitializeVariable(variable2);
        //variable2.insert(0,"%");
    }
    for(auto iter : GetValues()){
        if(iter->t_name == variable1){
            if(iter->t_type == value_t_type::DOUBLE)
                ifftype = value_t_type::DOUBLE;
            if(iter->t_name.at(0) == '%')
                //value1 = iter->t_source_number;
                value1 = "%"+std::to_string(iter->numberVariable);
            else
                value1 = "%"+std::to_string(iter->numberVariable);
            return_value1 = true;
        }
    }
    for(auto iter : GetValues()){
        if(iter->t_name == variable2){
            if(iter->t_type == value_t_type::DOUBLE)
                ifftype = value_t_type::DOUBLE;
            if(iter->t_name.at(0) == '%')
                value2 = "%"+std::to_string(iter->numberVariable);
                //value2 = iter->t_source_number;
            else
                value2 = "%"+std::to_string(iter->numberVariable);
            return_value2 = true;
        }
    }
    if(!return_value1 || !return_value2)
        return false;

     std::cout<<"value1:"<<value1<<",value2:"<<value2<<"\n";
    std::string operation_name = get_value_t_op_name(valueoptype);
    if(ifftype == value_t_type::DOUBLE)
        operation_name.insert(0,"f");
    std::string type_name = operation_name + " " + get_value_t_type_name(ifftype);
    addProgram("\n%"+std::to_string(lastNumber)+" = "+type_name+ " " + value1 + ", " + value2);
    lastNumber++;
    //addProgram("\n%"+std::to_string(lastNumber)+" = load "+get_value_t_type_name(ifftype)+ ", " +get_value_t_type_name(ifftype)+"* %"+ std::to_string(lastNumber-1) +" align "+std::to_string(get_value_t_byte_size(ifftype)));
    //lastNumber++;
    //AddVariable("%"+std::to_string(lastNumber),ifftype);
    //InitializeVariable("%"+std::to_string(lastNumber-1));
    //value_t new_number_var;
    int numberNewVar = lastNumber;
    std::string lastValue = lastVariable();
    //lastNumber++;
    if(!AddVariable("%result"+std::to_string(numberNewVar),ifftype))
        return false;
    if(!InitializeVariable("%result"+std::to_string(numberNewVar),lastValue))
        return false;
    result_operation = "%result"+std::to_string(numberNewVar);

    //new_number_var.t_name = "%"+std::to_string(lastNumber);
    //new_number_var.t_type = ifftype;
    //new_number_var.t_source_number = std::to_string(lastNumber);
    //new_number_var.numberVariable = lastNumber;
    //values_stack.back().push_back(new_number_var);
    //lastNumber++;

    //InitializeVariable("%"+std::to_string(lastNumber));
    //if(ifftype == value_t_type::INT)
    //    InitializeVariable("resultint",lastVariable(),ifftype);
    //if(ifftype == value_t_type::DOUBLE)
    //    InitializeVariable("resultdouble",lastVariable(),ifftype);
    return true;
}

value_t_type llvm_ir_generator::get_type_var(std::string value){
    if(value.find(".") != std::string::npos )
        return value_t_type::DOUBLE;
    else if(isdigit(value.at(0)))
        return value_t_type::INT;
    else{
        value_t* initialize_value = nullptr;
        for(auto iter : GetValues()){
            if(iter->t_name == value){
                initialize_value = iter;
                break;
            }
        }
        if(initialize_value == nullptr)
            return  value_t_type::ERROR;
        return  initialize_value->t_type;
    }
};
