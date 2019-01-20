
// Generated from d:\Programmes\Qt\Projets\PRD\PRD\ANTLR\Pivot.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "PivotParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by PivotParser.
 */
class  PivotVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by PivotParser.
   */
    virtual antlrcpp::Any visitFile(PivotParser::FileContext *context) = 0;

    virtual antlrcpp::Any visitStatements(PivotParser::StatementsContext *context) = 0;

    virtual antlrcpp::Any visitStatement(PivotParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitAction(PivotParser::ActionContext *context) = 0;

    virtual antlrcpp::Any visitLoop(PivotParser::LoopContext *context) = 0;

    virtual antlrcpp::Any visitWhile_loop(PivotParser::While_loopContext *context) = 0;

    virtual antlrcpp::Any visitUntil_loop(PivotParser::Until_loopContext *context) = 0;

    virtual antlrcpp::Any visitNumeric_expression(PivotParser::Numeric_expressionContext *context) = 0;

    virtual antlrcpp::Any visitNumeric_mul_div(PivotParser::Numeric_mul_divContext *context) = 0;

    virtual antlrcpp::Any visitNumeric_pow(PivotParser::Numeric_powContext *context) = 0;

    virtual antlrcpp::Any visitNumeric_inversion(PivotParser::Numeric_inversionContext *context) = 0;

    virtual antlrcpp::Any visitNumeric_atom(PivotParser::Numeric_atomContext *context) = 0;

    virtual antlrcpp::Any visitIf_elif_else(PivotParser::If_elif_elseContext *context) = 0;

    virtual antlrcpp::Any visitBoolean_expression(PivotParser::Boolean_expressionContext *context) = 0;

    virtual antlrcpp::Any visitBoolean_and(PivotParser::Boolean_andContext *context) = 0;

    virtual antlrcpp::Any visitBoolean_comparator(PivotParser::Boolean_comparatorContext *context) = 0;

    virtual antlrcpp::Any visitBoolean_not(PivotParser::Boolean_notContext *context) = 0;

    virtual antlrcpp::Any visitBoolean_atom(PivotParser::Boolean_atomContext *context) = 0;


};

