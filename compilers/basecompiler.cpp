#include "basecompiler.h"

#include "ANTLR/antlr4-runtime/PivotLexer.h"

/**
 * @brief Constructor of the BaseCompiler class
 */
BaseCompiler::BaseCompiler()
    : PivotVisitor()
{
}

// Methods ----------------------------------------------------------------------------------------

/**
 * @brief Returns the string representation in target language of the source code
 * @param source : The code to translate into target language
 * @return The string representation of the source code into target language
 */
string BaseCompiler::compile(const string &source)
{
    antlr4::ANTLRInputStream input(source);
    PivotLexer lexer(&input);
    antlr4::CommonTokenStream tokenStream(&lexer);
    PivotParser parser(&tokenStream);

    PivotParser::FileContext* tree = parser.file();

    string result = visitFile(tree).as<string>();
    return result;
}
