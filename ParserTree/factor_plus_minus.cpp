#ifndef FACTOR_PLUS_MINUS_H
#define FACTOR_PLUS_MINUS_H

#include "factor_plus_minus.h"
#include "antlr4-runtime/SceneParser.h"
#include "common.h"
#include "llvm_ir_generator.h"
#include "math_expression.h"
#include "factor.h"

void parse_factor_plus_minus(SceneParser::Factor_plus_minusContext* factor_plus_minus,
                             std::vector<SceneParser::Mult_divContext*>& mult_div,
                             int& number_plus_minus,
                             value_t_type& outputvaluettype,
                             math_result& result_plus_minus){
    std::cout<<"factor plus minus:"+factor_plus_minus->getText()+"\n";
    /*if(iter2->factor() && iter2->factor()->LEFT_SQUARE_BRACKET() != NULL && iter2->factor()->ID() == NULL){
        cout<<"init mass\n";
        result.count = 0;
        for(auto iter3 : iter2->factor()->NUMBER()){
            result.type = value_t_type::MASS;
            result.value.append(iter3->getText());
            result.count++;
        }
        return result;
    }*/
    if(factor_plus_minus->factor() && factor_plus_minus->factor()->STRING() != NULL){
        std::cout<<"string\n";
        number_plus_minus++;
        return;
    } /*else if(iter2->factor() && iter2->factor()->ID() != NULL){
        result.value = iter2->factor()->ID()->getText();
        for(auto iter_values : llvm_ir_generator::getGenerator()->GetValues()){
            if(iter_values->t_name == iter2->factor()->ID()){
                result.type = iter_values->t_type;
                break;
            }
        }
    }
    else if(iter2->factor() && iter2->factor()->NUMBER() != NULL && !iter2->factor()->LEFT_SQUARE_BRACKET()){
        result.value = iter2->factor()->NUMBER().at(0)->getText();
        result.type = llvm_ir_generator::getGenerator()->get_type_var(result.value);
    }*/
    if(factor_plus_minus->math_expression()){
        std::cout<<"math expression:"+factor_plus_minus->math_expression()->getText()+"\n";
        if(number_plus_minus != 0){
            if(mult_div.at(number_plus_minus-1)->MULT()){
                llvm_ir_generator::getGenerator()->OperationVariable(value_op_type::MUL,
                                                                     outputvaluettype,
                                                                     result_plus_minus.value,
                                                                     parse_math(factor_plus_minus->math_expression()).value);
                result_plus_minus.value = llvm_ir_generator::getGenerator()->result_operation;
                result_plus_minus.type = outputvaluettype;
            }
            if(mult_div.at(number_plus_minus-1)->DIV()){
                llvm_ir_generator::getGenerator()->OperationVariable(value_op_type::DIV,outputvaluettype,
                                                                     result_plus_minus.value,
                                                                     parse_math(factor_plus_minus->math_expression()).value);
                result_plus_minus.value = llvm_ir_generator::getGenerator()->result_operation;
                result_plus_minus.type = outputvaluettype;
            }
        } else{
            result_plus_minus = parse_math(factor_plus_minus->math_expression());
        }
    } else {
        std::cout<<"no math expression:\n";
        std::string current_value = factor_plus_minus->getText();
        if(factor_plus_minus->factor() && factor_plus_minus->factor()->function_call()){
            std::cout<<"function call:"+factor_plus_minus->factor()->function_call()->getText()+"\n";
            value_t_type return_type;
            std::vector<std::string> func_args;
            for(auto arg_iter : factor_plus_minus->factor()->function_call()->factor()){
                func_args.push_back(arg_iter->getText());
            }
            llvm_ir_generator::getGenerator()->CallFunction(factor_plus_minus->factor()->function_call()->ID()->getText(),
                                                            func_args,return_type);
            if(return_type == value_t_type::VOID)
                exit(1);
            current_value = llvm_ir_generator::getGenerator()->lastVariable();
        }
        if(number_plus_minus != 0 && mult_div.at(number_plus_minus-1)){
            if(mult_div.at(number_plus_minus-1)->MULT()){
                llvm_ir_generator::getGenerator()->OperationVariable(value_op_type::MUL,
                                                                     outputvaluettype,
                                                                     current_value,
                                                                     result_plus_minus.value);
                result_plus_minus.value = llvm_ir_generator::getGenerator()->result_operation;
                result_plus_minus.type = outputvaluettype;
                //resultdbl_plus_minus*=atof(iter2->getText().c_str());
            }
            if(mult_div.at(number_plus_minus-1)->DIV()){
                llvm_ir_generator::getGenerator()->OperationVariable(value_op_type::DIV,outputvaluettype,result_plus_minus.value,current_value);
                result_plus_minus.value = llvm_ir_generator::getGenerator()->result_operation;
                result_plus_minus.type = outputvaluettype;
                //resultdbl_plus_minus/=atof(iter2->getText().c_str());
            }
        } else {
            //resultdbl_plus_minus = atof(iter2->getText().c_str());
            result_plus_minus.value = current_value;
            if(factor_plus_minus->factor()){
            if(factor_plus_minus->factor()->LEFT_SQUARE_BRACKET()){
                std::cout<<"param mass elem\n";
                //int number = atoi(factor_plus_minus->factor()->INT()->toString().c_str());
                std::string number = parse_math(factor_plus_minus->factor()->math_expression()).value;
                if(!isdigit(number.at(0))){
                    llvm_ir_generator::getGenerator()->InitializeVariable(number);
                    number = llvm_ir_generator::getGenerator()->lastVariable();

                }
                llvm_ir_generator::getGenerator()->GetMassElem(factor_plus_minus->factor()->ID()->getText(),number,result_plus_minus.type);
                //result_plus_minus.type = value_t_type::MASS;
                number_plus_minus++;
                return;
            }
            }
            result_plus_minus.type = llvm_ir_generator::getGenerator()->get_type_var(current_value);
        }
    }
    number_plus_minus++;
}

#endif // FACTOR_PLUS_MINUS_H
