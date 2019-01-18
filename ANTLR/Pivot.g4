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
POW     : '^';
COMMA   : ',';
DOT     : '.';


// Specials
NEWLINE : ('\r'? '\n' | '\r')+;

WHITESPACE  : (' ' | '\t')+ -> skip;

// Keywords
FORWARD     : 'forward';
DURATION    : 'duration';
SPEED       : 'speed';
LOOP        : 'loop';
TIMES       : 'times';
END         : 'end';
IF          : 'if';
ELIF        : 'elif';
ELSE        : 'else';
TRUE        : 'true';
FALSE       : 'false';

// Parser #########################################################################################

file    : statements EOF;

statements  : (statement NEWLINE)* (statement NEWLINE?)?;

// Statements types
statement   : action
            | loop
            | if_elif_else
            ;

// Possible actions
action  : FORWARD DURATION AFF duration=numeric_expression (SPEED AFF speed=numeric_expression)?
        ;

// Loops
loop    : LOOP TIMES AFF repetition_number=numeric_expression SEP NEWLINE statements END;

// Numeric expressions
numeric_expression  : value+=numeric_mul_div (op=(PLUS|MINUS) value+=numeric_mul_div)*;
numeric_mul_div     : value+=numeric_pow (op=(STAR|DIV) value+=numeric_pow)*;
numeric_pow         : value+=numeric_inversion (POW value+=numeric_inversion)*;
numeric_inversion   : MINUS? numeric_atom;
numeric_atom        : NUMBER
                    | LPAR numeric_expression RPAR
                    ;

// Conditions
if_elif_else   :    IF if_condition=boolean_expression SEP NEWLINE if_block=statements
                    (ELIF elif_condition+=boolean_expression SEP NEWLINE elif_block+=statements)*
                    (ELSE SEP NEWLINE else_block=statements)?
                    END;

// Boolean expressions
boolean_expression  : value+=boolean_and (OR value+=boolean_and)*;
boolean_and         : value+=boolean_comparator (AND value+=boolean_comparator)*;
boolean_comparator  : left=boolean_not (comparator=(EQU|DIF|LT|GT|LEQ|GEQ) right=boolean_not)?;
boolean_not         : NOT? boolean_atom;
boolean_atom        : TRUE
                    | FALSE
                    | LPAR boolean_expression RPAR
                    ;