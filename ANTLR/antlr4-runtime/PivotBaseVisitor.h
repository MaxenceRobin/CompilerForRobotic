
// Generated from d:\Programmes\Qt\Projets\PRD\PRD\ANTLR\Pivot.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "PivotVisitor.h"


/**
 * This class provides an empty implementation of PivotVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  PivotBaseVisitor : public PivotVisitor {
public:

  virtual antlrcpp::Any visitFile(PivotParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(PivotParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAction(PivotParser::ActionContext *ctx) override {
    return visitChildren(ctx);
  }


};

