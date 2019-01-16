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
    void incrementInndentation();
    void decrementIndentation();
    string getIndentation();

private:
    virtual Any visitFile(PivotParser::FileContext* context) override;
    virtual Any visitStatement(PivotParser::StatementContext* context) override;
    virtual Any visitAction(PivotParser::ActionContext* context) override;

    virtual Any visitBoolean_expression(PivotParser::Boolean_expressionContext* context) override;
    virtual Any visitBoolean_and(PivotParser::Boolean_andContext* context) override;
    virtual Any visitBoolean_not(PivotParser::Boolean_notContext* context) override;
    virtual Any visitBoolean_atom(PivotParser::Boolean_atomContext* context) override;

private:
    unsigned int indentationCount;
};

#endif // MICROPYTHONCOMPILER_H
