#ifndef LLVM_IR_TYPES_H
#define LLVM_IR_TYPES_H

#include "string"
#include "vector"

#define STRING_MAX_SIZE "256"

enum value_t_type{
    ERROR = -1,
    INT = 0,
    DOUBLE = 1,
    STRING = 2,
    VOID = 3,
    MASS = 4,
    CLASS = 5
};

enum value_op_type{
    MUL = 0,
    DIV= 1,
    ADD = 2,
    SUB = 3
};

struct value_t{
    std::string t_name;
    std::string t_source_number;
    value_t_type t_type;
    value_t_type t_type2;
    std::string classname;
    std::string classs;
    bool isInitialized;
    int numberVariable;
};

struct function_t{
    std::string name;
    std::vector<value_t> values;
    value_t_type return_type;
};

static std::string get_value_t_type_name(value_t_type value){
    if(value == value_t_type::INT)
        return "i32";
    else if(value == value_t_type::DOUBLE)
        return "double";
    else if(value == value_t_type::STRING)
        return  "i8*";
    else if(value == value_t_type::VOID)
        return  "void";
    //else if(value == value_t_type::STRING)
    //    return "[" + std::string(STRING_MAX_SIZE) + " x i8]";
    else return "";
};

static int get_value_t_byte_size(value_t_type value){
    if(value == value_t_type::INT)
        return 4;
    else if(value == value_t_type::DOUBLE)
        return 8;
    else if(value == value_t_type::STRING)
        return 8;
    //else if(value == value_t_type::STRING)
    //    return 16;
    else return 0;
};

static std::string get_value_t_op_name(value_op_type valueoptype){
    if(valueoptype == value_op_type::MUL)
        return "mul";
    else if(valueoptype == value_op_type::DIV)
        return "div";
    else if(valueoptype == value_op_type::ADD)
        return "add";
    else if(valueoptype == value_op_type::SUB)
        return "sub";
    else return "";
};

#endif // LLVM_IR_TYPES_H


