#include "llvm_ir_generator.h"
#include <cctype>
#include <iostream>
#include "vector"

void llvm_ir_generator::beginAddFunction(std::string name, value_t_type return_type, std::vector<value_t> input_values){
    addMain = false;
    numberSymbolAdd = program.find("define i32 @main()");
    function_t new_function;
    new_function.name = name;
    new_function.return_type = return_type;
    new_function.values = input_values;
    functions.push_back(new_function);
    addProgram("\ndefine "+
               get_value_t_type_name(return_type)+
               " @"+name+"(");
    int number = 0;
    for(auto iter : input_values){
        if(number != 0)
            addProgram(",");
        addProgram(get_value_t_type_name(iter.t_type));
        addProgram(" %"+iter.t_source_number);
        number++;
    }
    copy_values_stack = values_stack;
    values_stack.clear();
    values_stack.push_back(std::list<value_t>());

    addProgram(") {\nentry:");
}

void llvm_ir_generator::endAddFunction(){
    addProgram("\n}\n");
    addMain = true;
    values_stack = copy_values_stack;
}


void llvm_ir_generator::AddReturn(value_t_type type, std::string value){
    //addProgram("\nret "+get_value_t_type_name(type) + " ");
}

bool llvm_ir_generator::CallFunction(std::string func_name, std::vector<std::string> args_input, value_t_type &return_value_type)
{
    std::vector<std::string> args;
    for(auto iter : args_input){
        value_t* initialize_value = NULL;
        if(isdigit(iter.at(0)))
        {
            args.push_back(iter);
            continue;
        }
        for(auto iter2 : GetValues()){
            if(iter2->t_name == iter){
                InitializeVariable(iter2->t_name);
                initialize_value = iter2;
            }
        }
        if(!initialize_value){
            return false;
        }

        args.push_back(std::to_string(initialize_value->numberVariable));
    }
    bool find = false;
    function_t func;
    for(auto iter : functions){
        if(iter.name == func_name){
            func = iter;
            find = true;
            break;
        }
    }
    if(!find)
        return false;
    return_value_type = func.return_type;
    int number = 0;
    if(return_value_type == value_t_type::VOID)
        addProgram("\ncall " + get_value_t_type_name(return_value_type) + " @"+func_name+"(");
    else{
        addProgram("\n%"+std::to_string(lastNumber)+std::string(" = call ") + get_value_t_type_name(return_value_type) + " @"+func_name+"(");
        value_t new_number_var;
        new_number_var.t_name = "%"+std::to_string(lastNumber);
        new_number_var.t_source_number = std::to_string(lastNumber);
        new_number_var.t_type = return_value_type;
        values_stack.back().push_back(new_number_var);
        lastNumber++;
    }
    for(auto iter : func.values){
        addProgram(get_value_t_type_name(iter.t_type) + " %" + args.at(number));
        number++;
        if(args.size() != number)
            addProgram(" , ");
    }
    addProgram(")");
    return true;
}

bool llvm_ir_generator::printf(std::string value)
{
    bool return_value = false;
    value_t_type t_type;
    int number_variable;
    InitializeVariable(value);
    for(auto iter : GetValues()){
        if(iter->t_name == value){
            t_type = iter->t_type;
            number_variable = iter->numberVariable;
            return_value = true;
            break;
        }
    }
    if(!return_value)
        return false;
    if(t_type == value_t_type::INT)
        addProgram("\ncall i32 @printint(i32 %"+std::to_string(number_variable)+")");
    if(t_type == value_t_type::DOUBLE)
        addProgram("\ncall i32 @printdouble(double %"+std::to_string(number_variable)+")");
    if(t_type == value_t_type::STRING)
        addProgram("\ncall i32 @puts(i8* %"+std::to_string(number_variable)+") nounwind");
    lastNumber++;
    return true;
}
