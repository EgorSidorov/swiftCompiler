
// Generated from Mygrammar.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "MygrammarVisitor.h"


/**
 * This class provides an empty implementation of MygrammarVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MygrammarBaseVisitor : public MygrammarVisitor {
public:

  virtual antlrcpp::Any visitCompileUnit(MygrammarParser::CompileUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(MygrammarParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerm(MygrammarParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFactor(MygrammarParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }


};

