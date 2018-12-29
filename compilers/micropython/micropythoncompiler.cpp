#include "ANTLR/antlr4-runtime/PivotLexer.h"
#include "micropythoncompiler.h"

using namespace antlr4;

/**
 * @brief Constructor of the MicroPython compiler class
 */
MicroPythonCompiler::MicroPythonCompiler()
    : PivotBaseVisitor()
{
}

// Methods ----------------------------------------------------------------------------------------

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
    string result = "File = {\n";

    for (const auto& statement : context->statement())
    {
        result += "\t" + visitStatement(statement).as<string>() + "\n";
    }

    result += "}";

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of a statement
 * @param context : The tree representation of the statement
 * @return The string that represents the MicroPython code of the statement
 */
Any MicroPythonCompiler::visitStatement(PivotParser::StatementContext *context)
{
    string result = "";

    if (context->action())
    {
        result = "<action> {\n\t\t" + visitAction(context->action()).as<string>() + "\n\t}";
    }

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
        result = "[command=forward] ";

        if (context->NUMBER())
        {
            result += "duration {" + context->NUMBER()->getText() + "}";
        }
        else if (context->WHILE())
        {
            result += "while {" + context->boolean_expression()->getText() + "}";
        }
        else if (context->UNTIL())
        {
            result += "until {" + context->boolean_expression()->getText() + "}";
        }
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
