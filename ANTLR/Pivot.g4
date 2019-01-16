grammar Pivot;

// Lexer ##########################################################################################

// Numbers
fragment DIGIT          : [0-9];
fragment NON_NULL_DIGIT : [1-9];
fragment INTEGER_PART   : (NON_NULL_DIGIT DIGIT* | '0');
fragment DECIMAL_PART   : '.' DIGIT+ ([eE] [+-]? DIGIT+)?;
NUMBER                  : INTEGER_PART (DECIMAL_PART)?;

// Booleans
EQU     : '==';
DIF     : '!=';
LT      : '<';
GT      : '>';
LEQ     : '<=';
GEQ     : '>=';
AND     : '&&';
OR      : '||';
NOT     : '!';

// Symbols
AFF     : '=';
LPAR    : '(';
RPAR    : ')';


// Specials
NEWLINE : ('\r'? '\n' | '\r')+;

WHITESPACE  : (' ' | '\t')+ -> skip;

// Keywords
FORWARD     : 'forward';
TRUE        : 'true';
FALSE       : 'false';
DURATION    : 'duration';
SPEED       : 'speed';

// Parser #########################################################################################

file    : (statement NEWLINE)* (statement NEWLINE?)? EOF;

// Statements types
statement   : action;

// Possible actions
action  : FORWARD DURATION AFF duration (SPEED AFF speed)?
        ;

duration    : NUMBER;
speed       : NUMBER;

// Boolean expressions
boolean_expression  : boolean_and (OR boolean_and)*;
boolean_and         : boolean_not (AND boolean_not)*;
boolean_not         : NOT? boolean_atom;
boolean_atom        : TRUE
                    | FALSE
                    | LPAR boolean_expression RPAR
                    ;