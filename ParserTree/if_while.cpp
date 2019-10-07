#include "if_while.h"

#include <iostream>
#include "llvm_ir_generator.h"
#include "expression.h"
#include <string>
#include <iostream>


void parse_if(SceneParser::IffContext* iff){
    std::string begin_if = llvm_ir_generator::getGenerator()->beginIF(iff->ID().at(0)->getText(),
                                                                      iff->ID().at(1)->getText(),
                                                                      iff->comparisons()->getText());
    for(auto it : iff->expression()){
        parse_expr(it);
    }
    llvm_ir_generator::getGenerator()->endIF(begin_if);
}

void parse_while(SceneParser::WhileeContext* whilee){
    std::string begin_if = llvm_ir_generator::getGenerator()->beginWHILE();
    for(auto it : whilee->expression()){
        parse_expr(it);
    }
    llvm_ir_generator::getGenerator()->endWHILE(begin_if,
                                                whilee->ID().at(0)->getText(),
                                                whilee->ID().at(1)->getText(),
                                                whilee->comparisons()->getText());
}
