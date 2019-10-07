#ifndef TERM_H
#define TERM_H

#include "antlr4-runtime/SceneParser.h"
#include <vector>
#include "common.h"

void parse_term(SceneParser::TermContext*,
                std::vector<SceneParser::Plus_minusContext*>&,
                math_result&,
                value_t_type&,
                int&);

#endif // TERM_H
