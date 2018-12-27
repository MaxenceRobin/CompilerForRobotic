#ifndef BASECOMPILER_H
#define BASECOMPILER_H

#include "ANTLR/antlr4-runtime/PivotVisitor.h"

#include <string>

using std::string;


/**
 * @brief This class represents the base of all compilers for the pivot language
 */
class BaseCompiler : public PivotVisitor
{
public:
    BaseCompiler();

    string compile(const string& source);
};

#endif // BASECOMPILER_H
