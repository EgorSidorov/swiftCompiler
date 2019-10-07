
// Generated from modelica.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "modelicaVisitor.h"


/**
 * This class provides an empty implementation of modelicaVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  modelicaBaseVisitor : public modelicaVisitor {
public:

  virtual antlrcpp::Any visitCompileUnit(modelicaParser::CompileUnitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(modelicaParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerm(modelicaParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFactor(modelicaParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }


};

