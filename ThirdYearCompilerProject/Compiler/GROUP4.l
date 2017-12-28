LETTER [a-zA-Z]
NUMBER [1-9]
ZNUMBER [0-9]
STR [\"][^\"]*[\"]
VARIABLE [a-zA-Z][_a-zA-Z0-9]*
PLS [\+]|[\-][\-]|[\+][\-][\+][\-]|[\-][\+][\-][\+]
MNS [\-]|[+]*[\-][+]*([\-][\+]*[\-][\+]*)*
%{
extern int yyerror(char *);
int yylineno;
%}
%%
"/%"((\%+[^/%])|([^%]))*\%*"%/" ;
boolean return BOOLEAN_KEY;
true|false return BOOLEAN_PARAM;
char return CHAR_KEY;
integer return INTEGER_KEY;
{NUMBER}{ZNUMBER}* return INTEGER_DEC;
0 return INTEGER_ZERO;
0[xX][0-9ABCDEF]+ return INTEGER_HEX;
0[0-7]+ return INTEGER_OCTAL;
[0-1]+b return INTEGER_BIN;
'[^']' return CHAR_VAL;
string return STRING_KEY;
{STR} return STRING_WORD;
var return VAR_KEY;
intptr return INTPTR_KEY;
charptr return CHAR_PTR;
if return IF_KEY;
else return ELSE_KEY;
while return WHILE_KEY;
procedure return PROCEDURE_KEY;
return return RETURN_KEY;
null return NULL_LEX;
&& return AND;
\|\| return OR;
\/ return DIVISION;
\* return MUL;
{PLS}+ return PLUS;
{MNS} return MINUS;
== return EQUAL;
\> return MORE;
\< return LESS;
\>= return MORE_EQUAL;
\<= return LESS_EQUAL;
! return NOT;
!= return NOT_EQUAL;
\^ return VALUE_OF;
& return ADDRESS_OF;
\| return ABSOLUTE;
\) return PAR_CLOSE;
\( return PAR_OPEN;
\} return BLOCK_CLOSE;
\{ return BLOCK_OPEN;
\[ return INDEX_OPEN;
\] return INDEX_CLOSE;
, return COMMA;
: return COLON;
= return ASSIGNMENT;
; return SEMICOLON;
{VARIABLE} return VAR;
[ ]+ ;
\n|\r|\t {if(*yytext == '\n'){yylineno++;}}
. {yyerror("undefiend keyword");}
%%