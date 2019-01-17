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
SEP     : ':';
PLUS    : '+';
MINUS   : '-';
DIV     : '/';
STAR    : '*';
COMMA   : ',';
DOT     : '.';
MATH    : 'Math';
POW     : 'pow';


// Specials
NEWLINE : ('\r'? '\n' | '\r')+;

WHITESPACE  : (' ' | '\t')+ -> skip;

// Keywords
FORWARD     : 'forward';
TRUE        : 'true';
FALSE       : 'false';
DURATION    : 'duration';
SPEED       : 'speed';
LOOP        : 'loop';
TIMES       : 'times';
END         : 'end';

// Parser #########################################################################################

file    : statements EOF;

statements  : (statement NEWLINE)* (statement NEWLINE?)?;

// Statements types
statement   : action
            | loop
            ;

// Possible actions
action  : FORWARD DURATION AFF duration=numeric_expression (SPEED AFF speed=numeric_expression)?
        ;

// Loops
loop    : LOOP TIMES AFF repetition_number=numeric_expression SEP NEWLINE statements END;

// Numeric expressions
numeric_expression  : value+=numeric_mul_div (op=(PLUS|MINUS) value+=numeric_mul_div)*;
numeric_mul_div     : value+=numeric_pow (op=(STAR|DIV) value+=numeric_pow)*;
numeric_pow         : numeric_inversion
                    | MATH DOT POW LPAR first=numeric_pow COMMA second=numeric_pow RPAR;
numeric_inversion   : MINUS? numeric_atom;
numeric_atom        : NUMBER
                    | LPAR numeric_expression RPAR
                    ;

// Boolean expressions
boolean_expression  : boolean_and (OR boolean_and)*;
boolean_and         : boolean_not (AND boolean_not)*;
boolean_not         : NOT? boolean_atom;
boolean_atom        : TRUE
                    | FALSE
                    | LPAR boolean_expression RPAR
                    ;