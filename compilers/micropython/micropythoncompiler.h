#ifndef MICROPYTHONCOMPILER_H
#define MICROPYTHONCOMPILER_H

#include "compilers/basecompiler.h"

using antlrcpp::Any;

/**
 * @brief MicroPython code generator from pivot code input
 * This class is a compiler for pivot code that generates MicroPython code as output
 */
class MicroPythonCompiler : public BaseCompiler
{
public:
    MicroPythonCompiler();

    virtual Any visitFile(PivotParser::FileContext* context) override;
    virtual Any visitStatement(PivotParser::StatementContext* context) override;
    virtual Any visitAction(PivotParser::ActionContext* context) override;

    virtual Any visitBoolean_expression(PivotParser::Boolean_expressionContext* context) override;
    virtual Any visitBoolean_and(PivotParser::Boolean_andContext* context) override;
    virtual Any visitBoolean_not(PivotParser::Boolean_notContext* context) override;
    virtual Any visitBoolean_atom(PivotParser::Boolean_atomContext* context) override;
};

#endif // MICROPYTHONCOMPILER_H
