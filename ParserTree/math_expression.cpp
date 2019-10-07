#ifndef MATH_EXPRESSION_H
#define MATH_EXPRESSION_H

#include "math_expression.h"
#include <iostream>
#include "llvm_ir_generator.h"
#include <string>
#include <iostream>
#include "antlr4-runtime/SceneParser.h"
#include "common.h"
#include "term.h"

math_result parse_math(SceneParser::Math_expressionContext* math){
    math_result result;
    value_t_type outputvaluettype;
    std::cout<<"parse math\n";
    if(math){
        std::cout<<"base:"+math->getText()+"\n";
        int number_mult_div = 0;
        std::vector<SceneParser::Plus_minusContext*> plus_minus = math->plus_minus();
        for(auto iter : math->term()){
            parse_term(iter,plus_minus,result,outputvaluettype,number_mult_div);
        }
    }
    return result;
}

#endif // MATH_EXPRESSION_H
