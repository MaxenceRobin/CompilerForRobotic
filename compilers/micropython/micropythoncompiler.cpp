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

    for (auto statement : context->statement())
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
            speed = context->speed()->getText();
        }

        result += "Avancer_droit(" + speed + ")\n";
        result += getIndentation() + "time.sleep(" + context->duration()->getText() + " * 1000)";
    }

    return std::move(result);
}

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
