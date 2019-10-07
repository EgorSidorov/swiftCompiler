#include "expression.h"
#include "llvm_ir_generator.h"
#include "math_expression.h"
#include <string>
#include <iostream>
#include "common.h"
#include "if_while.h"
#include "left_var_or_init.h"

void parse_expr(SceneParser::ExpressionContext* expr){
    if(expr->iff()){
        parse_if(expr->iff());
        return;
    }
    if(expr->whilee()){
        parse_while(expr->whilee());
        return;
    }
    if(expr->classelem()){
        llvm_ir_generator::getGenerator()->AddClass(expr->classelem()->ID().at(0)->getText());
        return;
    }
    SceneParser::AssignContext* left = expr->assign();
    bool has_left = true;
    bool has_left_var = false;
    bool has_left_init_type = false;
    if(expr->assign() == NULL)
        has_left = false;
    else {
        if(expr->assign()->INIT() != NULL)
            has_left_var = true;
        if(expr->assign()->INIT_TYPE() != NULL)
            has_left_init_type = true;
    }
    std::cout<<"\n\nbase\n";
    std::cout<<expr->getText()<<"\n";
    if(has_left){
        std::cout<<"this is init\n";
        parse_const_str(expr,has_left_var);
        cout_type(expr,has_left_var,has_left_init_type);
        if(has_left_var){
            parse_with_left_var(expr,has_left_init_type);
        } else {
            if(expr->assign()->mass_elem()){
                std::cout<<"init mass elem\n";
                //int number_elem = atoi(expr->assign()->mass_elem()->INT()->getText().c_str());
                std::string number_elem = parse_math(expr->assign()->mass_elem()->math_expression()).value;
                if(!isdigit(number_elem.at(0))){
                    llvm_ir_generator::getGenerator()->InitializeVariable(number_elem);
                    number_elem = llvm_ir_generator::getGenerator()->lastVariable();

                }

                llvm_ir_generator::getGenerator()->InitMass(expr->assign()->ID()->getText()
                                                            ,number_elem
                                                            ,parse_math(expr->math_expression()).value);
                return;
            }
            llvm_ir_generator::getGenerator()->InitializeVariable(expr->assign()->ID()->getText(),
                                                                 parse_math(expr->math_expression()).value);
        }
    } else {
        parse_without_left(expr);
    }
}

void parse_const_str(SceneParser::ExpressionContext* expr, bool has_left_var){
    if(expr->math_expression()){
        if(expr->math_expression()->term().size() == 1){
            if(expr->math_expression()->term().at(0)->factor_plus_minus().size() == 1){
                auto factor = expr->math_expression()->term().at(0)->factor_plus_minus().at(0)->factor();
                if(factor && factor->STRING() != NULL){
                    if(has_left_var){
                        llvm_ir_generator::getGenerator()->AddVariable(expr->assign()->ID()->getText(),
                                                                       value_t_type::STRING);
                    }
                        std::string str = factor->STRING()->getText();
                        if(str.size() < 2)
                            exit(1);
                        str.erase(0,1);
                        str.erase(str.end()-1,str.end());
                        std::cout<<str<<" "<<expr->assign()->ID()->getText()<<" ";
                        llvm_ir_generator::getGenerator()->InitializeStringConst(expr->assign()->ID()->getText(),
                                                                                 str);
                        return;
                }
            }
        }
    }
}
