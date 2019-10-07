
// Generated from modelica.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "modelicaParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by modelicaParser.
 */
class  modelicaVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by modelicaParser.
   */
    virtual antlrcpp::Any visitCompileUnit(modelicaParser::CompileUnitContext *context) = 0;

    virtual antlrcpp::Any visitExpr(modelicaParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitTerm(modelicaParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitFactor(modelicaParser::FactorContext *context) = 0;


};

