#ifndef FACTOR_PLUS_MINUS_H
#define FACTOR_PLUS_MINUS_H

#include "antlr4-runtime/SceneParser.h"
#include <vector>
#include <common.h>

void parse_factor_plus_minus(SceneParser::Factor_plus_minusContext*,
                             std::vector<SceneParser::Mult_divContext*>&,
                             int&,
                             value_t_type&,
                             math_result&);

#endif // FACTOR_PLUS_MINUS_H
