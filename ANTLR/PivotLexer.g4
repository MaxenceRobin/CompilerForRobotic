lexer grammar PivotLexer;

// Fragments --------------------------------------------------------------------------------------

// Numbers
fragment DIGIT          : [0-9];
fragment NON_NULL_DIGIT : [1-9];
fragment INTEGER        : (NON_NULL_DIGIT DIGIT* | '0');
fragment DECIMAL_PART   : '.' DIGIT+ ([eE] [+-]? DIGIT+)?;
fragment DECIMAL        : INTEGER DECIMAL_PART;
fragment NUMBER         : INTEGER DECIMAL_PART?;

// Booleans
fragment TRUE   : 'true';
fragment FALSE  : 'false';
fragment EQU    : '==';
fragment DIF    : '!=';
fragment LT     : '<';
fragment GT     : '>';
fragment LEQ    : '<=';
fragment GEQ    : '>=';
fragment AND    : '&&';
fragment OR     : '||';
fragment NOT    : '!';

// Symbols
fragment LPAR   : '(';
fragment RPAR   : ')';


// Specials
fragment NEWLINE    : ('\r'? '\n' | '\r')+;

WHITESPACE  : ' ' -> skip;

// Actual lexer rules -----------------------------------------------------------------------------
FORWARD     : 'forward';
DURATION    : NUMBER;
WHILE       : 'while';
UNTIL       : 'until';