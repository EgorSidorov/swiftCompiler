#ifndef TERM_H
#define TERM_H

#include <iostream>
#include "llvm_ir_generator.h"
#include <string>
#include <iostream>
#include "term.h"
#include "antlr4-runtime/SceneParser.h"
#include "common.h"
#include "factor_plus_minus.h"

void parse_term(SceneParser::TermContext* term,
                std::vector<SceneParser::Plus_minusContext*>& plus_minus,
                math_result& result,
                value_t_type& outputvaluettype,
                int& number_mult_div ){
    std::cout<<"term:"+term->getText()+"\n";
    //double resultdbl_plus_minus = 0;
    math_result result_plus_minus;
    int number_plus_minus = 0;
    std::vector<SceneParser::Mult_divContext*> mult_div = term->mult_div();
    for(auto iter2 : term->factor_plus_minus()){
        parse_factor_plus_minus(iter2,mult_div,number_plus_minus,outputvaluettype,result_plus_minus);
     }
    if(number_mult_div != 0){
        if(plus_minus.at(number_mult_div-1)->PLUS()){
            if(!llvm_ir_generator::getGenerator()->OperationVariable(value_op_type::ADD,outputvaluettype,
                                                                     result.value,result_plus_minus.value)){
                std::cout<<"error operation\n";
            }
            std::cout<<"sum"<<"\n";
            result.value = llvm_ir_generator::getGenerator()->result_operation;
            result.type = outputvaluettype;
            //result_dbl+=resultdbl_plus_minus;
        }
        if(plus_minus.at(number_mult_div-1)->MINUS()){
            std::cout<<"sub"<<"\n";
            if(!llvm_ir_generator::getGenerator()->OperationVariable(value_op_type::SUB,
                                                                 outputvaluettype,
                                                                 result.value,
                                                                 result_plus_minus.value)){
                std::cout<<"error operation\n";
            }
            result.value = llvm_ir_generator::getGenerator()->result_operation;
            result.type = outputvaluettype;
            //result_dbl-=resultdbl_plus_minus;
        }
        std::cout<<"result:"+result.value+"\n";
    } else {
        result = result_plus_minus;
    }

    number_mult_div++;
}

#endif // TERM_H
