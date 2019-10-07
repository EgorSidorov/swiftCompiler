#ifndef LEFT_VAR_OR_INIT_H
#define LEFT_VAR_OR_INIT_H

#include "antlr4-runtime/SceneParser.h"

void parse_with_left_var(SceneParser::ExpressionContext* expr, bool has_left_init_type);

void parse_without_left(SceneParser::ExpressionContext* expr);

#endif // LEFT_VAR_OR_INIT_H
