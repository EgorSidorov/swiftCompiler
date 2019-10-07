#ifndef EXPRESSION_H
#define EXPRESSION_H

#include "antlr4-runtime/SceneParser.h"

void parse_expr(SceneParser::ExpressionContext*);
void parse_const_str(SceneParser::ExpressionContext* expr, bool has_left_var);

#endif // EXPRESSION_H
