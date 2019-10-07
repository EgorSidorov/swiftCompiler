#ifndef MATH_EXPRESSION_H
#define MATH_EXPRESSION_H

#include "antlr4-runtime/SceneParser.h"
#include "common.h"

math_result parse_math(SceneParser::Math_expressionContext*);

#endif // MATH_EXPRESSION_H
