parser grammar Pivot;
import PivotLexer;

file                : (statement NEWLINE)* (statement NEWLINE?)?;

// Statements types
statement           : action;

// Possible actions
action              : FORWARD DURATION
                    | FORWARD WHILE boolean_expression
                    ;

// Boolean expressions
boolean_expression  : boolean_and (OR boolean_and)*;
boolean_and         : boolean_not (AND boolean_not)*;
boolean_not         : NOT? boolean_atom;
boolean_atom        : TRUE
                    | FALSE
                    | LPAR boolean_expression RPAR
                    ;