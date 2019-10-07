grammar Scene; 

program: (expression END_EXPR)* EOF;
math_expression: term( plus_minus term )*;
create_mass: LEFT_SQUARE_BRACKET number (COMMA number)* RIGHT_SQUARE_BRACKET;
mass_elem: (LEFT_SQUARE_BRACKET math_expression RIGHT_SQUARE_BRACKET);
expression :  
           math_expression 
           | iff 
           | whilee 
           | assign math_expression
           | classelem
           | lett;
assign : INIT ID INIT_TYPE EQUI | ID mass_elem? EQUI | INIT ID EQUI | method_id EQUI;
function_call : ID LEFT_BRACKET factor (',' factor)* RIGHT_BRACKET;
method_call : method_id LEFT_BRACKET number? RIGHT_BRACKET;
mult_div: MULT|DIV; 
plus_minus: PLUS|MINUS;
iff            : IF    ID comparisons ID LEFT_FIG_BRACKET (expression END_EXPR)* RIGHT_FIG_BRACKET;
lett           : LET ID EQUI ID LEFT_BRACKET RIGHT_BRACKET;
whilee         : WHILE ID comparisons ID LEFT_FIG_BRACKET (expression END_EXPR)* RIGHT_FIG_BRACKET;
comparisons   : '>' | '<' | '=''=' | '!''=';
classelem         : CLASS ID LEFT_FIG_BRACKET ((INIT ID (EQUI INT | DOTS ID '?') END_EXPR) | (functionelem RIGHT_FIG_BRACKET) | (END_EXPR))* RIGHT_FIG_BRACKET;
functionelem      : 'func ' ID '(' ('_ ' ID DOTS INIT_TYPE)? ')' LEFT_FIG_BRACKET (END_EXPR)* (expression END_EXPR)* RIGHT_FIG_BRACKET;

PLUS          : '+' ; 
MINUS         : '-'; 
MULT          : '*'; 
DIV           : '/'; 
LEFT_BRACKET  : '(';
COMMA         : ',';
IF            : 'if ';
WHILE         : 'while ';
CLASS         : 'class ';
LEFT_SQUARE_BRACKET  : '[';
LEFT_FIG_BRACKET  : '{';
RIGHT_BRACKET : ')';
RIGHT_SQUARE_BRACKET  : ']';
RIGHT_FIG_BRACKET  : '}';
EQUI          : '=';
DOTS          : ':';
DOT          : '.';
LET          : 'let ';
method_id     : ID DOT  ID;

COMMENT 
: ( '//' ~[\r\n]* '\r'? '\n' 
| '/*' .*? '*/'
) -> skip 
; 

DOUBLE : INT '.' [0-9]+;
INT : [0-9]+; 
END_EXPR : ';'|'\n';
INIT : 'var ';
//TYPE : 'Int' | 'Double';
//INIT_TYPE : ':' TYPE;
INIT_TYPE : ':Int' | ':Double' | ':String';      
ID : [a-zA-Z][a-zA-Z_0-9]*;
CHAR: [a-zA-Z0-9];
STRING: '"'  CHAR*? '"';
FOR_LOOP: 'for ';
WHITESPACE : ' ' -> skip;
OPTIONAL :'!' -> skip;

number : '-'? (INT | DOUBLE); 
term: factor_plus_minus (mult_div factor_plus_minus )*; 
factor_plus_minus: factor | LEFT_BRACKET math_expression RIGHT_BRACKET;
factor: number | ID(LEFT_SQUARE_BRACKET math_expression RIGHT_SQUARE_BRACKET)? | function_call | STRING | create_mass | method_call |;