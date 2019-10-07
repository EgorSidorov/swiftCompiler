#ifndef COMMON_H
#define COMMON_H

#include "antlr4-runtime/SceneParser.h"
#include <string>
#include "llvm_ir_types.h"

value_t_type detect_type(std::string expr);

void cout_type(SceneParser::ExpressionContext* expr, bool has_left_var, bool has_left_init_type);

struct math_result{
    value_t_type type;
    std::string value;
    int count;
};

#endif // COMMON_H
