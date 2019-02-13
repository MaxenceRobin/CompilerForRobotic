
// Generated from .\Pivot.g4 by ANTLR 4.7.1

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

  virtual antlrcpp::Any visitStatements(PivotParser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(PivotParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAction(PivotParser::ActionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(PivotParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(PivotParser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(PivotParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoop(PivotParser::LoopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhile_loop(PivotParser::While_loopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUntil_loop(PivotParser::Until_loopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumeric_expression(PivotParser::Numeric_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumeric_mul_div(PivotParser::Numeric_mul_divContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumeric_pow(PivotParser::Numeric_powContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumeric_inversion(PivotParser::Numeric_inversionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumeric_atom(PivotParser::Numeric_atomContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_elif_else(PivotParser::If_elif_elseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolean_expression(PivotParser::Boolean_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolean_and(PivotParser::Boolean_andContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolean_comparator(PivotParser::Boolean_comparatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolean_not(PivotParser::Boolean_notContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolean_atom(PivotParser::Boolean_atomContext *ctx) override {
    return visitChildren(ctx);
  }


};

