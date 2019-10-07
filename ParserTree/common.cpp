#include "common.h"
#include <iostream>

value_t_type detect_type(std::string expr){
    if(expr.empty())
        return value_t_type::ERROR;
    bool isNumber = true;
    for(int iter = 0; iter < expr.length(); iter++){
        if(expr[iter] == '(' || expr[iter] == ')' || expr[iter] == '*' || expr[iter] == '+' || expr[iter] == '-' || expr[iter] == '/')
            continue;
        if(!isdigit(expr[iter]) && expr[iter] != '.'){
            isNumber = false;
            break;
        }
    }
    bool isMass = false;
    for(int iter = 0; iter < expr.length(); iter++){
        if(expr[iter] == '[' || expr[iter] == ']'){
            isMass = true;
            continue;
        }
        if(expr[iter] == '(' || expr[iter] == ')' || expr[iter] == '*' || expr[iter] == '+' || expr[iter] == '-' || expr[iter] == '/' || expr[iter] == ',')
            continue;
        if(!isdigit(expr[iter]) && expr[iter] != '.'){
            isMass = false;
            break;
        }
    }
    if(expr.find(".") != std::string::npos && isNumber)
        return value_t_type::DOUBLE;
    else if(isNumber)
        return value_t_type::INT;
    else if(isMass)
        return value_t_type::MASS;
    //else if()
    //    return value_t_type::CLASS;
    return value_t_type();
}

void cout_type(SceneParser::ExpressionContext *expr, bool has_left_var, bool has_left_init_type){
    if(has_left_var){
        if(has_left_init_type){
            std::string type_string = expr->assign()->INIT_TYPE()->toString();
            type_string.erase(type_string.begin(),type_string.begin()+1);
            std::cout<<"user definition type " +type_string + "\n";
        } else {
            std::string type_string;
            std::string right_side = expr->getText();
            right_side.erase(right_side.begin(),right_side.begin()+expr->assign()->getText().length());
            if(detect_type(right_side) == value_t_type::INT)
                type_string = "Int";
            if(detect_type(right_side) == value_t_type::DOUBLE)
                type_string = "Double";
            if(detect_type(right_side) == value_t_type::MASS)
                type_string = "Mass";
            if(detect_type(right_side) == value_t_type::CLASS)
                type_string = "Class";
            std::cout<<"auto definition type " +type_string + "\n";
        }
    } else {
        std::cout<<"existing variable\n";
    }
}
