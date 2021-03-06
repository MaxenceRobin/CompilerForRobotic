#ifndef MICROPYTHONCOMPILER_H
#define MICROPYTHONCOMPILER_H

#include "ANTLR/antlr4-runtime/PivotBaseVisitor.h"

using antlrcpp::Any;
using std::string;

/**
 * @brief MicroPython code generator from pivot code input
 * This class is a compiler for pivot code that generates MicroPython code as output
 */
class MicroPythonCompiler : public PivotBaseVisitor
{
public:
    MicroPythonCompiler();

    string getMicroPythonFromPivot(const string& pivot);

protected:
    void initialize();
    void incrementIndentation();
    void decrementIndentation();
    string getIndentation();

private:
    virtual Any visitFile(PivotParser::FileContext* context) override;
    virtual Any visitStatements(PivotParser::StatementsContext* context) override;
    virtual Any visitStatement(PivotParser::StatementContext* context) override;
    virtual Any visitAction(PivotParser::ActionContext* context) override;
    virtual Any visitSpecial_color(PivotParser::Special_colorContext* context) override;
    virtual Any visitDeclaration(PivotParser::DeclarationContext* context) override;
    virtual Any visitAssignment(PivotParser::AssignmentContext* context) override;
    virtual Any visitExpression(PivotParser::ExpressionContext* context) override;
    virtual Any visitLoop(PivotParser::LoopContext* context) override;
    virtual Any visitWhile_loop(PivotParser::While_loopContext* context) override;
    virtual Any visitUntil_loop(PivotParser::Until_loopContext* context) override;

    virtual Any visitNumeric_expression(PivotParser::Numeric_expressionContext* context) override;
    virtual Any visitNumeric_mul_div(PivotParser::Numeric_mul_divContext* context) override;
    virtual Any visitNumeric_pow(PivotParser::Numeric_powContext* context) override;
    virtual Any visitNumeric_inversion(PivotParser::Numeric_inversionContext* context) override;
    virtual Any visitNumeric_atom(PivotParser::Numeric_atomContext* context) override;
    virtual Any visitSpecial_numerics(PivotParser::Special_numericsContext* context) override;

    virtual Any visitIf_elif_else(PivotParser::If_elif_elseContext* context) override;

    virtual Any visitBoolean_expression(PivotParser::Boolean_expressionContext* context) override;
    virtual Any visitBoolean_and(PivotParser::Boolean_andContext* context) override;
    virtual Any visitBoolean_comparator(PivotParser::Boolean_comparatorContext* context) override;
    virtual Any visitBoolean_not(PivotParser::Boolean_notContext* context) override;
    virtual Any visitBoolean_atom(PivotParser::Boolean_atomContext* context) override;

    string visitRGB(antlr4::tree::TerminalNode* node);

private:
    unsigned int indentationCount;
};

#endif // MICROPYTHONCOMPILER_H
