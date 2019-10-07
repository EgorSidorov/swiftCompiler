#include "llvm_ir_generator.h"
#include <cctype>
#include <iostream>
#include "vector"

std::string llvm_ir_generator::beginWHILE()
{
    values_stack.push_back(std::list<value_t>());
    addProgram("\nbr label %"+std::to_string(lastNumber));
    addProgram("\n");
    addProgram("\n; <label>:"+std::to_string(lastNumber)+":");
    lastNumber++;
    return std::to_string(lastNumber-1);
}

std::string llvm_ir_generator::beginIF(std::string variable1, std::string variable2, std::string op)
{
    values_stack.push_back(std::list<value_t>());
    InitializeVariable(variable1);
    InitializeVariable(variable2);
    value_t var1;
    for(auto iter : GetValues()){
        if(iter->t_name == variable1){
            var1 = *iter;
            break;
        }
    }
    value_t var2;
    for(auto iter : GetValues()){
        if(iter->t_name == variable2){
            var2 = *iter;
            break;
        }
    }

    std::string name_op = "";
    std::string name_cmp = "cmp";
    if(op == "<")
        name_op = "lt";
    else if(op == ">")
        name_op = "gt";
    else if(op == "==")
        name_op = "eq";
    if(var1.t_type == value_t_type::DOUBLE){
        name_op.insert(0,"o");
        name_cmp.insert(0,"f");
    } else {
        if(name_op != "eq")
            name_op.insert(0,"s");
        name_cmp.insert(0,"i");
    }

    addProgram("\n%" + std::to_string(lastNumber) +
                   " = "+name_cmp+" " + name_op +
                   " "+get_value_t_type_name(var1.t_type) + " %" + std::to_string(var1.numberVariable) +
                   ", %" + std::to_string(var2.numberVariable));
    lastNumber++;
    addProgram("\nbr i1 "+lastVariable()+
                   ", label %"+std::to_string(lastNumber)+", label %"+"_setif%"+std::to_string(lastNumber)+"_");
    addProgram("\n");
    addProgram("\n; <label>:"+std::to_string(lastNumber)+":");
    lastNumber++;
    return "_setif"+lastVariable()+"_";
}

void llvm_ir_generator::endIF(std::string begin_if_label)
{
    addProgram("\nbr label %"+std::to_string(lastNumber));
    program.replace(program.find(begin_if_label),begin_if_label.length(),std::to_string(lastNumber));
    addProgram("\n");
    addProgram("\n; <label>:"+std::to_string(lastNumber)+":");
    lastNumber++;
    values_stack.pop_back();
    //lastNumber++;
    //addProgram("\n"+lastVariable()+" = add i32 2, 3");
}

void llvm_ir_generator::endWHILE(std::string begin_if_label,std::string variable1, std::string variable2, std::string op)
{
    InitializeVariable(variable1);
    InitializeVariable(variable2);
    value_t var1;
    for(auto iter : GetValues()){
        if(iter->t_name == variable1){
            var1 = *iter;
            break;
        }
    }
    value_t var2;
    for(auto iter : GetValues()){
        if(iter->t_name == variable2){
            var2 = *iter;
            break;
        }
    }

    std::string name_op = "";
    std::string name_cmp = "cmp";
    if(op == "<")
        name_op = "lt";
    else if(op == ">")
        name_op = "gt";
    else if(op == "==")
        name_op = "eq";
    if(var1.t_type == value_t_type::DOUBLE){
        name_op.insert(0,"o");
        name_cmp.insert(0,"f");
    } else {
        name_op.insert(0,"s");
        name_cmp.insert(0,"i");
    }
    addProgram("\n%" + std::to_string(lastNumber) +
                   " = "+name_cmp+" " + name_op +
                   " "+get_value_t_type_name(var1.t_type) + " %" + std::to_string(var1.numberVariable) +
                   ", %" + std::to_string(var2.numberVariable));
    addProgram("\nbr i1 %"+std::to_string(lastNumber)+", label %" + begin_if_label+", label %"+ std::to_string(lastNumber+1));
    addProgram("\n");
    lastNumber++;
    addProgram("\n; <label>:"+std::to_string(lastNumber)+":");
    lastNumber++;
    values_stack.pop_back();
}

std::string llvm_ir_generator::lastVariable(){
    return std::string("%")+std::to_string(lastNumber-1);
}
