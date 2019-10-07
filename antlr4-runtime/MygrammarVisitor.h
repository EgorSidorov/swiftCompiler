
// Generated from Mygrammar.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "MygrammarParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MygrammarParser.
 */
class  MygrammarVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MygrammarParser.
   */
    virtual antlrcpp::Any visitCompileUnit(MygrammarParser::CompileUnitContext *context) = 0;

    virtual antlrcpp::Any visitExpr(MygrammarParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitTerm(MygrammarParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitFactor(MygrammarParser::FactorContext *context) = 0;


};

