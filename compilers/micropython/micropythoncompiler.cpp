#include "ANTLR/antlr4-runtime/PivotLexer.h"
#include "micropythoncompiler.h"

using namespace antlr4;

#include <QDebug>

/**
 * @brief Constructor of the MicroPython compiler class
 */
MicroPythonCompiler::MicroPythonCompiler()
    : PivotBaseVisitor()
{
}

/**
 * @brief Initializes the intern attributes used during the compilation process
 */
void MicroPythonCompiler::initialize()
{
    indentationCount = 0;
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Increments the number of indentations
 */
void MicroPythonCompiler::incrementInndentation()
{
    indentationCount++;
}

/**
 * @brief Decrements the number of indentation, or does nothing if the value is already 0
 */
void MicroPythonCompiler::decrementIndentation()
{
    if (indentationCount > 0)
    {
        indentationCount--;
    }
}

/**
 * @brief Returns the current indentation
 * @return the current indentation
 */
string MicroPythonCompiler::getIndentation()
{
    string result = "";

    for (unsigned int i = 0; i < indentationCount; i++)
    {
        result += "\t";
    }

    return result;
}

/**
 * @brief Returns the MicroPython code for the given pivot code
 * @param pivot : The code to translate into MicroPython
 * @return The MicroPython code for the given pivot code
 */
string MicroPythonCompiler::getMicroPythonFromPivot(const string &pivot)
{
    ANTLRInputStream stream(pivot);
    PivotLexer lexer(&stream);
    CommonTokenStream tokens(&lexer);
    PivotParser parser(&tokens);

    PivotParser::FileContext* tree = parser.file();

    initialize();
    string result = visitFile(tree).as<string>();

    return result;
}

/**
 * @brief Returns the MicroPython representation of a file
 * @param context : The tree representation of the file
 * @return The string that represents the MicroPython code of the file
 */
Any MicroPythonCompiler::visitFile(PivotParser::FileContext *context)
{
    string result = "if __name__ == \"__main__\" :\n";
    incrementInndentation();

    for (auto statement : context->statements()->statement())
    {
        result += visitStatement(statement).as<string>();
    }

    decrementIndentation();

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of a statement
 * @param context : The tree representation of the statement
 * @return The string that represents the MicroPython code of the statement
 */
Any MicroPythonCompiler::visitStatement(PivotParser::StatementContext *context)
{
    string result = getIndentation();

    if (context->action())
    {
        result += visitAction(context->action()).as<string>();
    }
    else if (context->loop())
    {
        result += visitLoop(context->loop()).as<string>();
    }

    result += "\n";

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of an action
 * @param context : The tree representation of the action
 * @return The string that represents the MicroPython code of the action
 */
Any MicroPythonCompiler::visitAction(PivotParser::ActionContext *context)
{
    string result = "";

    if (context->FORWARD())
    {
        string speed = "V_MOYEN";

        if (context->SPEED())
        {
            speed = context->speed->getText();
        }

        result += "Avancer_droit(" + speed + ")\n";
        result += getIndentation() + "time.sleep(" + context->duration->getText() + " * 1000)";
    }

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of a loop
 * @param context : The tree representation of the loop
 * @return The string that represents the MicroPython code of the loop
 */
Any MicroPythonCompiler::visitLoop(PivotParser::LoopContext *context)
{
    string result = "for _ in range(" + visitNumeric_expression(context->repetition_number).as<string>() + ") :\n";
    incrementInndentation();

    for (auto statement : context->statements()->statement())
    {
        result += visitStatement(statement).as<string>();
    }

    decrementIndentation();
    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of a numeric expression
 * @param context : The tree representation of the numeric expression
 * @return The string that represents the MicroPython code of the numeric expression
 */
Any MicroPythonCompiler::visitNumeric_expression(PivotParser::Numeric_expressionContext* context)
{
    string result = "";
    bool first = true;
    unsigned int operatorNumber = 0;

    for (auto currentValue : context->value)
    {
        if (!first)
        {
            result += context->op[operatorNumber].getText();
            operatorNumber++;
        }

        result += visitNumeric_mul_div(currentValue).as<string>();
        first = false;
    }

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of a numeric multiplication or division
 * @param context : The tree representation of a numeric multiplication or division
 * @return The string that represents the MicroPython code of the numeric multiplication or division
 */
Any MicroPythonCompiler::visitNumeric_mul_div(PivotParser::Numeric_mul_divContext* context)
{
    string result = "";
    bool first = true;
    unsigned int operatorNumber = 0;

    for (auto currentValue : context->value)
    {
        if (!first)
        {
            result += context->op[operatorNumber].getText();
            operatorNumber++;
        }

        result += visitNumeric_pow(currentValue).as<string>();
        first = false;
    }

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of a power expression
 * @param context : The tree representation of the power expression
 * @return The string that represents the MicroPython code of the power expression
 */
Any MicroPythonCompiler::visitNumeric_pow(PivotParser::Numeric_powContext* context)
{
    string result = "";

    if (context->MATH())
    {
        result = visitNumeric_expression(context->first).as<string>() + "**" + visitNumeric_expression(context->second).as<string>();
    }
    else
    {
        result = visitNumeric_inversion(context->numeric_inversion()).as<string>();
    }

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of a numeric inversion
 * @param context : The tree representation of the numeric inversion
 * @return The string that represents the MicroPython code of the numeric inversion
 */
Any MicroPythonCompiler::visitNumeric_inversion(PivotParser::Numeric_inversionContext* context)
{
    string result = visitNumeric_atom(context->numeric_atom()).as<string>();

    if (context->MINUS())
    {
        result = "-" + result;
    }

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of a numeric atom
 * @param context : The tree representation of the numeric atom
 * @return The string that represents the MicroPython code of the numeric atom
 */
Any MicroPythonCompiler::visitNumeric_atom(PivotParser::Numeric_atomContext* context)
{
    if (context->NUMBER())
    {
        return context->getText();
    }
    else
    {
        return "(" + visitNumeric_expression(context->numeric_expression()).as<string>() + ")";
    }
}

// En attente ##################################################################

Any MicroPythonCompiler::visitBoolean_expression(PivotParser::Boolean_expressionContext* context)
{
    return context->getText();
}

Any MicroPythonCompiler::visitBoolean_and(PivotParser::Boolean_andContext* context)
{
    return context->getText();
}

Any MicroPythonCompiler::visitBoolean_not(PivotParser::Boolean_notContext* context)
{
    return context->getText();
}

Any MicroPythonCompiler::visitBoolean_atom(PivotParser::Boolean_atomContext* context)
{
    return context->getText();
}
