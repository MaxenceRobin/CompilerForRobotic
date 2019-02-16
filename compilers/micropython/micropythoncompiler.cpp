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
void MicroPythonCompiler::incrementIndentation()
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
    /*string result = visitStatements(context->statements()).as<string>();
    return std::move(result);*/
    return visitStatements(context->statements());
}

/**
 * @brief Returns the MicroPython representation of a block of statements
 * @param context : The tree representation of a block of statements
 * @return The string that represents the MicroPython code of the block of statements
 */
Any MicroPythonCompiler::visitStatements(PivotParser::StatementsContext* context)
{
    string result = "";

    for (auto statement : context->statement())
    {
        result += visitStatement(statement).as<string>();
    }

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
        result += visitAction(context->action()).as<string>() + "\n";
    }
    else if (context->declaration())
    {
        result += visitDeclaration(context->declaration()).as<string>() + "\n";
    }
    else if (context->assignment())
    {
        result += visitAssignment(context->assignment()).as<string>() + "\n";
    }
    else if (context->loop())
    {
        result += visitLoop(context->loop()).as<string>();
    }
    else if (context->if_elif_else())
    {
        result += visitIf_elif_else(context->if_elif_else()).as<string>();
    }
    else if (context->while_loop())
    {
        result += visitWhile_loop(context->while_loop()).as<string>();
    }
    else if (context->until_loop())
    {
        result += visitUntil_loop(context->until_loop()).as<string>();
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

    // Movement actions -------------------------
    if (context->move_type)
    {
        const string moveType = context->move_type->getText();

        if (moveType == "forward")
        {
            result = "Avancer_droit";
        }
        else if (moveType == "backward")
        {
            result = "Reculer_droit";
        }
        else if (moveType == "left")
        {
            result = "Pivoter_gauche";
        }
        else if (moveType == "right")
        {
            result = "Pivoter_droite";
        }

        result += "(";
        const string moveSpeed = context->move_speed->getText();

        if (moveSpeed == "slow")
        {
            result += "V_MIN";
        }
        else if (moveSpeed == "normal")
        {
            result += "V_MOYEN";
        }
        else if (moveSpeed == "fast")
        {
            result += "V_MAX";
        }

        result += ")";

    }
    // Stoping action ---------------------------
    else if (context->STOP())
    {
        result = "Arret()";
    }
    // Waiting action ---------------------------
    else if (context->WAIT())
    {
        result = "time.sleep(" + visitNumeric_expression(context->duration).as<string>() + ")";
    }
    else if (context->LED())
    {
        string color = "";

        if (context->RGB())
        {
            color = visitRGB(context->RGB());
        }
        else if (context->special_color())
        {
            color = visitSpecial_color(context->special_color()).as<string>();
        }
        else if (context->VARIABLE())
        {
            color = context->VARIABLE()->getText();
        }

        result = "pycom.rgbled(" + color + ")";
    }

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of a special color expression
 * @param context : The tree representation of the special color expression
 * @return The string that represents the MicroPython code of the special color expression
 */
Any MicroPythonCompiler::visitSpecial_color(PivotParser::Special_colorContext* context)
{
    string result = "";

    if (context->RANDOMCOLOR())
    {
        result = "random_color()";
    }

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of an assignment
 * @param context : The tree representation of the assignment
 * @return The string that represents the MicroPython code of the assignment
 */
Any MicroPythonCompiler::visitDeclaration(PivotParser::DeclarationContext* context)
{
    string result = "";

    bool first = true;
    for (auto variable : context->var_name)
    {
        if (!first)
        {
            result += "\n" + getIndentation();
        }

        result += variable->getText() + " = 0";
        first = false;
    }

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of an assignment
 * @param context : The tree representation of the assignment
 * @return The string that represents the MicroPython code of the assignment
 */
Any MicroPythonCompiler::visitAssignment(PivotParser::AssignmentContext* context)
{
    string result = context->VARIABLE()->getText() + " = " + visitExpression(context->expression()).as<string>();
    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of an expression
 * @param context : The tree representation of the expression
 * @return The string that represents the MicroPython code of the expression
 */
Any MicroPythonCompiler::visitExpression(PivotParser::ExpressionContext* context)
{
    string result = "";

    if (context->numeric_expression())
    {
        result = visitNumeric_expression(context->numeric_expression()).as<string>();
    }
    else if (context->boolean_expression())
    {
        result = visitBoolean_expression(context->boolean_expression()).as<string>();
    }
    else if (context->RGB())
    {
        result = visitRGB(context->RGB());
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

    incrementIndentation();
    result += visitStatements(context->statements()).as<string>();
    decrementIndentation();

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of a while loop
 * @param context : The tree representation of the while loop
 * @return The string that represents the MicroPython code of the while loop
 */
Any MicroPythonCompiler::visitWhile_loop(PivotParser::While_loopContext* context)
{
    string result = "while " + visitBoolean_expression(context->condition).as<string>() + " :\n";

    incrementIndentation();
    result += visitStatements(context->statements()).as<string>();
    decrementIndentation();

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of a until loop
 * @param context : The tree representation of the until loop
 * @return The string that represents the MicroPython code of the until loop
 */
Any MicroPythonCompiler::visitUntil_loop(PivotParser::Until_loopContext *context)
{
    string result = "while True :\n";

    incrementIndentation();
    result += visitStatements(context->statements()).as<string>();
    result += getIndentation() + "if " + visitBoolean_expression(context->condition).as<string>() + " :\n";
        incrementIndentation();
        result += getIndentation() + "break\n";
        decrementIndentation();
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
            result += context->op[operatorNumber]->getText();
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
            result += context->op[operatorNumber]->getText();
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
    bool first = true;

    for (auto currentValue : context->value)
    {
        if (!first)
        {
            result += "**";
        }

        result += visitNumeric_inversion(currentValue).as<string>();
        first = false;
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
    string result = "";

    if (context->NUMBER() || context->VARIABLE())
    {
        result = context->getText();
    }
    else if (context->special_numerics())
    {
        result = visitSpecial_numerics(context->special_numerics()).as<string>();
    }
    else
    {
        result = "(" + visitNumeric_expression(context->numeric_expression()).as<string>() + ")";
    }

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of a special numeric element
 * @param context : The tree representation of the special numeric element
 * @return The string that represents the MicroPython code of the special numeric element
 */
Any MicroPythonCompiler::visitSpecial_numerics(PivotParser::Special_numericsContext* context)
{
    string result = "";

    if (context->VERYCLOSE())
    {
        result = "d_Thd1";
    }
    else if (context->CLOSE())
    {
        result = "d_Thd2";
    }
    else if (context->LEFT_SENSOR())
    {
        result = "Distance[0]";
        //result = "capteur_d_l_VL6180X[0].range_mesure()";
    }
    else if (context->CENTER_SENSOR())
    {
        result = "Distance[1]";
        //result = "capteur_d_l_VL6180X[1].range_mesure()";
    }
    else if (context->RIGHT_SENSOR())
    {
        result = "Distance[2]";
        //result = "capteur_d_l_VL6180X[3].range_mesure()";
    }

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of an if-elif-else expression
 * @param context : The tree representation of the if-elif-else expression
 * @return The string that represents the MicroPython code of the if-elif-else expression
 */
Any MicroPythonCompiler::visitIf_elif_else(PivotParser::If_elif_elseContext* context)
{
    incrementIndentation();
    string result = "if " + visitBoolean_expression(context->if_condition).as<string>() + " :\n" + visitStatements(context->if_block).as<string>();
    decrementIndentation();

    unsigned int blockNumber = 0;
    for (auto currentElif : context->elif_condition)
    {
        result += getIndentation() + "elif ";

        incrementIndentation();
        result += visitBoolean_expression(currentElif).as<string>() + " :\n" + visitStatements(context->elif_block[blockNumber]).as<string>();
        decrementIndentation();

        blockNumber++;
    }

    if (context->ELSE())
    {
        result += getIndentation() + "else :\n";

        incrementIndentation();
        result += visitStatements(context->else_block).as<string>();
        decrementIndentation();
    }

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of a boolean expression
 * @param context : The tree representation of the boolean expression
 * @return The string that represents the MicroPython code of the boolean expression
 */
Any MicroPythonCompiler::visitBoolean_expression(PivotParser::Boolean_expressionContext* context)
{
    string result = "";
    bool first = true;

    for (auto currentValue : context->value)
    {
        if (!first)
        {
            result += " or ";
        }

        result += visitBoolean_and(currentValue).as<string>();
        first = false;
    }

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of an and expression
 * @param context : The tree representation of the and expression
 * @return The string that represents the MicroPython code of the and expression
 */
Any MicroPythonCompiler::visitBoolean_and(PivotParser::Boolean_andContext* context)
{
    string result = "";
    bool first = true;

    for (auto currentValue : context->value)
    {
        if (!first)
        {
            result += " and ";
        }

        result += visitBoolean_comparator(currentValue).as<string>();
        first = false;
    }

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of an comparison
 * @param context : The tree representation of the comparison
 * @return The string that represents the MicroPython code of the comparison
 */
Any MicroPythonCompiler::visitBoolean_comparator(PivotParser::Boolean_comparatorContext* context)
{
    string result = visitBoolean_not(context->left).as<string>();

    if (context->right)
    {
        result += context->comparator->getText() + visitBoolean_not(context->right).as<string>();
    }

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of a not expression
 * @param context : The tree representation of the not expression
 * @return The string that represents the MicroPython code of the not expression
 */
Any MicroPythonCompiler::visitBoolean_not(PivotParser::Boolean_notContext* context)
{
    string result = visitBoolean_atom(context->boolean_atom()).as<string>();

    if (context->NOT())
    {
        result = "not " + result;
    }

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of a boolean atom
 * @param context : The tree representation of the boolean atom
 * @return The string that represents the MicroPython code of the boolean atom
 */
Any MicroPythonCompiler::visitBoolean_atom(PivotParser::Boolean_atomContext* context)
{
    string result = "";

    if (context->LPAR())
    {
        result = "(" + visitBoolean_expression(context->boolean_expression()).as<string>() + ")";
    }
    else if (context->TRUE())
    {
        result = "True";
    }
    else if (context->VARIABLE())
    {
        result = context->VARIABLE()->getText();
    }
    else if (context->FALSE())
    {
        result = "False";
    }
    else if (context->numeric_expression())
    {
        result = visitNumeric_expression(context->numeric_expression()).as<string>();
    }

    return std::move(result);
}

/**
 * @brief Returns the MicroPython representation of an RGB expression
 * @param context : The tree representation of the RGB expression
 * @return The string that represents the MicroPython code of the RGB expression
 */
string MicroPythonCompiler::visitRGB(antlr4::tree::TerminalNode* node)
{
    string color = node->getText();
    color.replace(0, 1, "0x");
    return color;
}
