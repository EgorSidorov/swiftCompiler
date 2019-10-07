#ifndef LEFT_VAR_OR_INIT_H
#define LEFT_VAR_OR_INIT_H

#include "left_var_or_init.h"
#include "llvm_ir_generator.h"
#include "math_expression.h"
#include <string>
#include <iostream>

void parse_with_left_var(SceneParser::ExpressionContext* expr, bool has_left_init_type){
    if(has_left_init_type){
        std::string type_string = expr->assign()->INIT_TYPE()->toString();
        type_string.erase(type_string.begin(),type_string.begin()+1);
        if(type_string == "Double")
            llvm_ir_generator::getGenerator()->AddVariable(expr->assign()->ID()->getText(),value_t_type::DOUBLE);
        if(type_string == "Int")
            llvm_ir_generator::getGenerator()->AddVariable(expr->assign()->ID()->getText(),value_t_type::INT);
        llvm_ir_generator::getGenerator()->InitializeVariable(expr->assign()->ID()->getText(),parse_math(expr->math_expression()).value);
    } else {
        std::cout<<"not init type\n";
        bool isMass = false;
        if(expr->math_expression()){
            if(expr->math_expression()->term().size()==1){
                if(expr->math_expression()->term().at(0)->factor_plus_minus().size() == 1){
                    if(expr->math_expression()->term().at(0)->factor_plus_minus().at(0)->factor()){
                        if(expr->math_expression()->term().at(0)->factor_plus_minus().at(0)->factor()->create_mass()){
                            SceneParser::Create_massContext* mass = expr->math_expression()->term().at(0)->factor_plus_minus().at(0)->factor()->create_mass();

                            std::cout<<mass->number().size()<<"\n";
                            if(mass->number().size()>0){
                                llvm_ir_generator::getGenerator()->AddMass(expr->assign()->ID()->getText()
                                                                        ,llvm_ir_generator::getGenerator()->get_type_var(mass->number().at(0)->getText())
                                                                        ,mass->number().size());
                                for(int ii = 0; ii < mass->number().size(); ii++){
                                    llvm_ir_generator::getGenerator()->InitMass(expr->assign()->ID()->getText()
                                                                                ,std::to_string(ii)
                                                                                ,mass->number().at(ii)->getText());
                                }

                            }
                            std::cout<<"create mass "<<expr->assign()->ID()->getText()<<"\n";
                            isMass = true;
                        }
                    }
                }
            }
        }
        if(expr->math_expression() && !isMass){
            std::cout<<"math expression\n";
            math_result result = parse_math(expr->math_expression());
            llvm_ir_generator::getGenerator()->AddVariable(expr->assign()->ID()->getText(),result.type);
            llvm_ir_generator::getGenerator()->InitializeVariable(expr->assign()->ID()->getText(),result.value);
        }
    }
}

void parse_without_left(SceneParser::ExpressionContext* expr){
    if(expr->lett()){
        std::cout<<"init object\n";
        llvm_ir_generator::getGenerator()->AddObject(expr->lett()->ID().at(0)->getText(),expr->lett()->ID().at(1)->getText());
    }
    else if(expr->math_expression() && expr->math_expression()->term().size() == 1 && expr->math_expression()->term().at(0)
            && expr->math_expression()->term().at(0)->factor_plus_minus().size() == 1 &&
            expr->math_expression()->term().at(0)->factor_plus_minus().at(0)->factor() &&
             expr->math_expression()->term().at(0)->factor_plus_minus().at(0)->factor()->method_call()){
        SceneParser::Method_callContext* methodcall = expr->math_expression()->term().at(0)->factor_plus_minus().at(0)->factor()->method_call();
        std::string name_object = methodcall->method_id()->ID().at(0)->getText();
        std::string name_method = methodcall->method_id()->ID().at(1)->getText();
        std::cout<<"method call "<<name_object<<"."<<name_method<<"\n";
        if(!methodcall->number())
            llvm_ir_generator::getGenerator()->CallMethod(name_object,name_method,false,"");
        else
            llvm_ir_generator::getGenerator()->CallMethod(name_object,name_method,true,methodcall->number()->getText());
    }
    else if(expr->math_expression()){
        if(expr->math_expression()->term().size() == 1){
            if(expr->math_expression()->term().at(0)->factor_plus_minus().size() == 1){
                auto factor = expr->math_expression()->term().at(0)->factor_plus_minus().at(0)->factor();
                if(factor &&
                        factor->function_call() != NULL &&
                        factor->function_call()->ID()->getText() == "print"){
                    for(auto someiter : factor->function_call()->factor()){
                        //cout<<someiter->getText();
                        llvm_ir_generator::getGenerator()->printf(someiter->getText());
                    }
                    return;
                }
            }
        }
    }
}

#endif // LEFT_VAR_OR_INIT_H
