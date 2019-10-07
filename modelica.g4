grammar modelica; 

PLUS : '+'; 
MINUS : '-'; 
MULT : '*'; 
DIV : '/'; 

compileUnit 
: expr EOF 
; 

COMMENT 
: ( '//' ~[\r\n]* '\r'? '\n' 
| '/*' .*? '*/' 
) -> skip 
; 

INT : ('0'..'9')+ ; 
DOUBLE : ('0'..'9')+('.'('0'..'9')+)?; 
ID : [a-zA-Z]+ ; 
WS : (' ' | '\r' | '\n') -> skip; 

NUMBER : INT | DOUBLE; 

expr: term( ( PLUS | MINUS) term )*; 
term: factor ( ( MULT | DIV) factor )*; 
factor: NUMBER;