grammar Pivot;

// Lexer ##########################################################################################

// Keywords (Must be defined first to avoid conflict with oter token, such as variables)
FORWARD     : 'forward';
BACKWARD    : 'backward';
LEFT        : 'left';
RIGHT       : 'right';
STOP        : 'stop';
DURATION    : 'duration';
NORMAL      : 'normal';
SLOW        : 'slow';
FAST        : 'fast';
WAIT        : 'wait';
LOOP        : 'loop';
END         : 'end';
IF          : 'if';
ELIF        : 'elif';
ELSE        : 'else';
TRUE        : 'true';
FALSE       : 'false';
WHILE       : 'while';
UNTIL       : 'until';
LED         : 'led';
RANDOMCOLOR : 'randomColor';
VAR         : 'var';

// Values
fragment DIGIT          : '0'..'9';
fragment NON_NULL_DIGIT : '1'..'9';
fragment LOWER_LETTER   : 'a'..'z';
fragment UPPER_LETTER   : 'A'..'Z';
fragment LETTER         : (LOWER_LETTER | UPPER_LETTER);
fragment INTEGER_PART   : (NON_NULL_DIGIT DIGIT* | '0');
fragment DECIMAL_PART   : '.' DIGIT+ ([eE] [+-]? DIGIT+)?;
fragment HEXA           : (DIGIT | 'a'..'f' | 'A'..'F');
fragment TRIPLE_HEXA    : HEXA HEXA HEXA;
NUMBER                  : INTEGER_PART (DECIMAL_PART)?;
RGB                     : '#' TRIPLE_HEXA TRIPLE_HEXA?;
VARIABLE                : LETTER (LETTER | DIGIT | '_')*;

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
AFF         : '=';
LPAR        : '(';
RPAR        : ')';
SEP         : ':';
PLUS        : '+';
MINUS       : '-';
DIV         : '/';
STAR        : '*';
POW         : '^';
COMMA       : ',';
SEMICOLON   : ';';
DOT         : '.';


// Specials
NEWLINE : ('\r'? '\n' | '\r')+;

WHITESPACE  : (' ' | '\t')+ -> skip;

// Parser #########################################################################################

file    : NEWLINE? statements EOF;

statements  : (statement NEWLINE)* statement?;

// Statements types
statement   : action
            | declaration
            | assignment
            | loop
            | while_loop
            | until_loop
            | if_elif_else
            ;

// Possible actions
action  : move_type=(FORWARD|BACKWARD|LEFT|RIGHT) move_speed=(SLOW|NORMAL|FAST)
        | STOP
        | WAIT duration=numeric_expression
        | LED (RGB|RANDOMCOLOR|VARIABLE)
        ;

// Declarations and assignments
declaration : VAR var_name+=VARIABLE (COMMA var_name+=VARIABLE)* SEMICOLON;
assignment  : VARIABLE AFF expression;

expression   : numeric_expression | boolean_expression | RGB;

// Loops
loop    : LOOP repetition_number=numeric_expression SEP NEWLINE statements END;

while_loop  : WHILE condition=boolean_expression SEP NEWLINE statements END;

until_loop  : UNTIL condition=boolean_expression SEP NEWLINE statements END;

// Numeric expressions
numeric_expression  : value+=numeric_mul_div (op=(PLUS|MINUS) value+=numeric_mul_div)*;
numeric_mul_div     : value+=numeric_pow (op=(STAR|DIV) value+=numeric_pow)*;
numeric_pow         : value+=numeric_inversion (POW value+=numeric_inversion)*;
numeric_inversion   : MINUS? numeric_atom;
numeric_atom        : NUMBER
                    | VARIABLE
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
                    | VARIABLE
                    | numeric_expression
                    | LPAR boolean_expression RPAR
                    ;