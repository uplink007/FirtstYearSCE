%{
#define YYDEBUG 1
#define SEVEN 7
#define N 1000
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//------------------newer structs------------------------
typedef enum type {TYPE_ERROR=-1,TYPE_INTEGER,TYPE_CHAR,TYPE_STRING,TYPE_INT_PTR,TYPE_CHAR_PTR,TYPE_BOOLEAN, TYPE_NULL} Type;
typedef struct error_string error_string;
struct error_string{
	char* error_str;
	error_string* next;
};
error_string* error_head=NULL;
typedef struct symbal_data symbal_data;
typedef struct symbal_node symbal_node;
struct symbal_data{//null if block start
	char* name;
	int type_node; //bloc=1 var=2
	char* type_val;
	struct ast_node* value;
	symbal_node* last_def_arg;
};
struct symbal_node{
	symbal_data* data;
	symbal_node* prev;
	symbal_node* top;
};
//-----------------new structs--------------------
struct ast_node // for binary/unary operators and expression lists //exp+exp  //L-2sons M-1son
{
  	int node_type;  
	Type type;
	int line;
  	struct ast_node * left;
  	struct ast_node * right;
};
struct tac_node
{
  	int num;  
	char* row;
  	struct tac_node * up;
  	struct tac_node * down;
};
struct string_list{
	struct ast_node* node;
	struct ast_node* next;
};
struct ast_relational_node // for relational operators  //exp>=exp  //R
{
  	int node_type;  //LESS/MORE....	
	int line;
	Type type;
  	char* operator;
  	struct ast_node * left;
  	struct ast_node * right;
};
struct ast_equality_node // for equality operators //exp==exp|| exp!=exp  //E
{
  	int node_type;
	Type type;
	int line;
  	char* operator;
  	struct ast_node * left;
  	struct ast_node * right;
};
struct ast_function_node // for function calls //foo()  //F
{
  	int node_type;
  	struct ast_node * arguments;
  	char* name;
	int line;
	Type type;
};
struct ast_symbol_reference_node // for symbol references //VAR  //S
{
  	int node_type;
	//int line;
	Type type;
  	char* name; 
};
struct ast_if_node // for "if/else" statements  //I 
//type set
{
  	int node_type;
	Type type;
	int line;
  	struct ast_node * condition;
  	struct ast_node * if_branch;
  	struct ast_node * else_branch;
};
struct ast_while_node // for "while" statements  //W
//type set
{
  	int node_type;
	Type type;
	int line;
  	struct ast_node * condition;
  	struct ast_node * while_branch;
};
struct ast_assignment_node // for assignment expressions  //x=5  //A
//type set
{
  	int node_type;
	Type type;
	int line;
  	struct ast_node * name;
  	struct ast_node * value;
};
struct ast_number_node // for constant floating-point numbers // 5  //N
//type set
{
	int node_type;
	Type type;
  	char* value;
};
struct ast_block_node  // B
//type set
{
	int node_type;
	Type type;
	struct ast_node * commands;
};
struct ast_procedure_node   // P  
//type set
{
	int node_type;  
	Type type;
	struct ast_node * name;
	struct ast_node * return_type;
	int line;
	struct ast_node * args;
	struct ast_node * funcblock;
};
struct ast_return_node   // Z
{
	int node_type;
	Type type;
	struct ast_node * left;
};
struct ast_func_block_node   // Y
{
	int node_type;
	Type type;
	struct ast_node * commands;
	struct ast_node * return_stm;
};
struct ast_def{ //D
//type set
	int node_type;
	Type type;
	struct ast_node * vars;
	struct ast_node * type2;
};
struct ast_address_of_node{ //C
	int node_type;
	Type type;
	int operator;
	struct ast_node * name;		
};
struct ast_def_index_of_node{ //G
//type already define as char* =="string" 
	int node_type;
	char type2[SEVEN];
        Type type;
	struct ast_node * name;		
};
struct ast_var_index_of_node{ //H
	int node_type;
	//int line;
	Type type;
	struct ast_node * name;
	struct ast_node * value;		
};
struct ast_index_original_node{ //O
	int node_type;
	Type type;
	struct ast_node * name;		
};
struct ast_abs_node{ //J
	int node_type;	
	Type type;
	int operator;
	struct ast_node * name;		
};
struct ast_value_of_node{ //V
	int node_type;
	Type type;
	int operator; //'^'
	struct ast_node * left;		
};
//----------------- new funcs list ---------------
char* Error = NULL;
void Error_Func(char* new_error);
void Error_Func_line(char* new_error, int line);
struct ast_node * new_ast_def(struct ast_node* vars,struct ast_node* type);
struct ast_node * new_ast_node (int node_type, struct ast_node * left, struct ast_node * right);
struct ast_node * new_ast_relational_node (char* operator, struct ast_node * left, struct ast_node * right);
struct ast_node * new_ast_equality_node (char* operator,struct ast_node * left, struct ast_node * right);
struct ast_node * new_ast_function_node (char* name, struct ast_node * arguments);
struct ast_node * new_ast_symbol_reference_node (char* name);
struct ast_node * new_ast_if_node (struct ast_node * condition, struct ast_node * if_branch, struct ast_node * else_branch);
struct ast_node * new_ast_while_node (struct ast_node * condition, struct ast_node * while_branch);
struct ast_node * new_ast_assignment_node (struct ast_node * name, struct ast_node * value);
struct ast_node * new_ast_number_node (char* value);
struct ast_node * new_ast_block_node(struct ast_node * commands);
struct ast_node * new_ast_procedure_node(struct ast_node * name, struct ast_node * r_type, struct ast_node * args, struct ast_node * f_block);
struct ast_node * new_ast_return_node(struct ast_node *left);
struct ast_node * new_ast_func_block_node(struct ast_node *left, struct ast_node *right);
struct ast_node * new_string_list(struct ast_node* node,struct ast_node* next);
struct ast_node * new_ast_def_index_of_node(struct ast_node * name);
struct ast_node * new_ast_var_index_of_node(struct ast_node * name,struct ast_node * value);
struct ast_node * new_ast_index_original_node(struct ast_node * name);
struct ast_node * new_ast_abs_node(int operator,struct ast_node * name);
struct ast_node * new_ast_value_of_node(int operator,struct ast_node * left);
char* strcatt(char* string1,char* string2);
//-------------------------- symbol table building --------------------------------------------
Type get_type_from_string(char* type);
symbal_node* tail;
void insert_var(struct ast_node* new_node,struct ast_node* new_node_type,int func);
symbal_node* get_symbal_node(char* name,int all_symbal_table);
char* get_symbal_type(char* str);
void insert_args_in_func_symbal_data(symbal_node* node,symbal_node* last_arg);
/*void print_symbol_table(symbal_node* tail_node);*/
//-------------------------- 3 Address Code--------------------------------------------
struct tac_node* tac_head;
char stack[100];
char* str_stack[100];
char stack_val = 'A'; 
char *mkrndstr();
//-------------------------- end of new structs --------------------------------------------
// struct symbol_node * new_symbol_node(char*name,char* value,char* type,struct symbol_node* next,struct symbol_node* next_block,struct symbol_node* prev);
// struct symbol_node* putSymbol(char*name,char* value,char* type,struct symbol_node* next,struct symbol_node* next_block,struct symbol_node* prev);
// struct symbol_node* getSymbol(char *varname);
// int installSymbol(char* varname,char* value,char* type,struct symbol_node* next,struct symbol_node* next_block,struct symbol_node* prev); 
void print_ast_tree (struct ast_node * ast_tree,int);
void print_tac_tree (struct ast_node * ast_tree);
void free_ast_tree (struct ast_node * ast_tree);
struct ast_node * new_ast_address_of_node(int operator,struct ast_node * name);
char* printType(Type type);
void return_def_length_and_types(struct ast_node* node,int** arr,int* length );
#define YYSTYPE struct ast_node*
int count_tac;
int yylineno;
int maincount;
int mainflag;
//int yydebug=1;
char temp_string[N];
%}
%token BOOLEAN_KEY,BOOLEAN_PARAM,CHAR_KEY,INTEGER_KEY,INTEGER_DEC
%token INTEGER_ZERO,INTEGER_HEX,INTEGER_OCTAL,INTEGER_BIN,CHAR_VAL
%token STRING_KEY,STRING_WORD,VAR_KEY,INTPTR_KEY,CHAR_PTR,IF_KEY
%token ELSE_KEY,WHILE_KEY,PROCEDURE_KEY,RETURN_KEY,NULL_LEX,AND,OR,DIVISION
%token MUL,PLUS,MINUS,EQUAL,MORE,LESS,MORE_EQUAL,LESS_EQUAL,NOT
%token NOT_EQUAL,VALUE_OF,ADDRESS_OF,ABSOLUTE,PAR_CLOSE,PAR_OPEN,BLOCK_CLOSE
%token BLOCK_OPEN,INDEX_OPEN,INDEX_CLOSE,COMMA,COLON,VAR,ASSIGNMENT,SEMICOLON,ERROR
%right ASSIGNMENT
%left AND,OR
%left EQUAL,NOT_EQUAL,MORE_EQUAL,LESS_EQUAL,MORE,LESS
%left MUL,DIVISION
%left PLUS,MINUS
%right NOT
%right VALUE_OF,ADDRESS_OF
%left SEMICOLON
%%
s:funcs {printf("start tree----->\n"); print_ast_tree($1,0);print_tac_tree($1);}
;
funcs:func {$$=$1;}
     |func funcs {$$=new_ast_node('L',$1,$2); }
     |error {yyerror("You can use global space only for functions");exit(0);}
     ;
func:PROCEDURE_KEY var PAR_OPEN func_vars PAR_CLOSE return_key type block_func {$$ = new_ast_procedure_node($2,$7,$4,$8);}
    |PROCEDURE_KEY var PAR_OPEN PAR_CLOSE return_key type block_func {$$ = new_ast_procedure_node($2,$6,NULL,$7);}
    |PROCEDURE_KEY error {
    if(strcmp(yytext,")")==0){
      yyerror("Expecting for (");
      }
    else if(strcmp(yytext,"return")==0){
      yyerror("Expecting for )");
    }else {
      strcpy(temp_string,"Wrong declatarion of the function look before :");
      yyerror(strcat(temp_string,yytext));
    }
		exit(0);}
    ; 
return_key:RETURN_KEY {$$ = new_ast_symbol_reference_node(yytext);}
condition:IF_KEY PAR_OPEN expressions PAR_CLOSE block {$$ = new_ast_if_node($3,$5,NULL);}
         |IF_KEY PAR_OPEN expressions PAR_CLOSE block ELSE_KEY block {$$ = new_ast_if_node($3,$5,$7);}
         |WHILE_KEY PAR_OPEN expressions PAR_CLOSE block {$$ = new_ast_while_node($3,$5);}
         |IF_KEY error {yyerror("IF Condition statement have a problem");exit(0);}
	 |WHILE_KEY error  {yyerror("WHILE Condition statement have a problem");exit(0);}
         ;
block:BLOCK_OPEN condition_block_stm BLOCK_CLOSE {$$ = new_ast_block_node($2);}
     |BLOCK_OPEN BLOCK_CLOSE {$$ = new_ast_block_node(NULL);}
     |BLOCK_OPEN error {yyerror("Block problem");exit (0);}
//close open block error
     ;
block_func:BLOCK_OPEN func_stm BLOCK_CLOSE {$$ = $2;}
          |error  {
                    yyerror("Expecting for block open");
                    exit(0);
                  }
          |BLOCK_OPEN func_stm error  {
                    yyerror("Expecting for block close");
                    exit(0);
                  }
          |BLOCK_OPEN error BLOCK_CLOSE {yyerror("function block has syntax error");exit(0);}
          ;
var:VAR {$$ = new_ast_symbol_reference_node(yytext);}
   ;
func_stm:block_stm return_key expressions SEMICOLON {$$ = new_ast_func_block_node($1,$3);}
        |return_key expressions SEMICOLON {$$ = new_ast_func_block_node(NULL,$2);}
	|block_stm error  {  
		   if(yytext[0]=='}')
			 yyerror("expecting semicolon") ;
		   else {
				strcpy(temp_string,"syntax error:  ");
				yyerror(strcat(temp_string,yytext));
			}
			exit(0);
		}
        ;
expressions:exp_bool {$$=$1;}
           ;
condition_block_stm:func_stm {$$=$1;}
                   |block_stm {$$=$1;}
                   ;
block_stm:definition_stm {$$=$1;}
         |assignment_stm {$$=$1;}
         |condition {$$=$1;}
         |func {$$=$1;}
         |definition_stm block_stm {$$=new_ast_node('L',$1,$2);}
         |assignment_stm block_stm {$$=new_ast_node('L',$1,$2);}
         |condition block_stm {$$=new_ast_node('L',$1,$2);}
         |func block_stm {$$=new_ast_node('L',$1,$2);}
         |block {$$=$1;}
         |block block_stm {$$=new_ast_node('L',$1,$2);}
         ;
definition_stm:VAR_KEY vars COLON type SEMICOLON {$$=new_ast_def($2,$4);}
              ;
function_vars:vars COLON type {$$=new_ast_def($1,$3);}
;
type:BOOLEAN_KEY {$$ = new_ast_symbol_reference_node(yytext);}
    |CHAR_KEY {$$ = new_ast_symbol_reference_node(yytext);}
    |INTEGER_KEY {$$ = new_ast_symbol_reference_node(yytext);}
    |string_key {$$=$1;}
    |INTPTR_KEY {$$ = new_ast_symbol_reference_node(yytext);}
    |CHAR_PTR {$$ = new_ast_symbol_reference_node(yytext);}
    |string_key index {$$ = new_ast_def_index_of_node($2);}
    |error {yyerror("Type error ");exit(0);}
    ;
string_key:STRING_KEY {$$ = new_ast_symbol_reference_node(yytext);}
          ;
vars:var{$$=new_string_list($1,NULL);}
    |var COMMA vars {$$=new_string_list($1,$3);}
    ;
func_vars:function_vars {$$=$1;}
         |func_vars SEMICOLON function_vars {$$=new_ast_node('L',$1,$3);}
         |error { //strcpy(temp_string,"Wrong declatarion of the function :");
                  yyerror("Var declaretion incomplite");
                  exit(0);
                }
         ; 
//func_var_type:vars COLON type {$$=new_ast_node('L',$1,$3);}
             ;
assignment_stm:var ASSIGNMENT assignment_var SEMICOLON {$$ = new_ast_assignment_node($1,$3);}
              |var index ASSIGNMENT assignment_var SEMICOLON {$$ = new_ast_assignment_node(new_ast_var_index_of_node($1,$2),$4);}
              |value_of ASSIGNMENT assignment_var SEMICOLON {$$ = new_ast_assignment_node($1,$3);}
              |var error SEMICOLON {yyerror("assignment problem");exit(0);}
	      ;
assignment_var:expressions {$$=$1;}
              |func_to_assignment {$$=$1;}
              |null_lex {$$=$1;}
              ;
null_lex:NULL_LEX {$$ = new_ast_symbol_reference_node(yytext);}
        ;
func_to_assignment:var PAR_OPEN func_input PAR_CLOSE {$$ = new_ast_function_node(((struct ast_symbol_reference_node*)$1)->name,$3);}
                  |var PAR_OPEN PAR_CLOSE {$$ = new_ast_function_node(((struct ast_symbol_reference_node*)$1)->name,NULL);}
                  ;
func_input:expressions {$$=$1;}
          |expressions COMMA func_input {$$=new_ast_node('L',$1,$3);}
          |func_to_assignment {$$=$1;}
          |func_to_assignment COMMA func_input {$$=new_ast_node('L',$1,$3);}
          |null_lex {$$=$1;}
          |null_lex COMMA func_input {$$=new_ast_node('L',$1,$3);}
          ; 
exp_bool:bool_param {$$ = $1;}
        |not bool_param {$$=new_ast_node('L',$1,$2);}
        |exp {$$=$1;}
        |str_word {$$=$1;}
        |exp_bool OR exp_bool {$$=new_ast_equality_node("||",$1,$3);}
        |exp_bool AND exp_bool {$$=new_ast_equality_node("&&",$1,$3);}
        |exp_bool EQUAL exp_bool {$$=new_ast_equality_node("==",$1,$3);}
        |exp_bool NOT_EQUAL exp_bool {$$=new_ast_equality_node("!=",$1,$3);}
        |PAR_OPEN exp_bool OR exp_bool PAR_CLOSE {$$=new_ast_equality_node("||",$2,$4);}
        |PAR_OPEN exp_bool AND exp_bool PAR_CLOSE {$$=new_ast_equality_node("&&",$2,$4);}
        |PAR_OPEN exp_bool EQUAL exp_bool PAR_CLOSE {$$=new_ast_equality_node("==",$2,$4);}
        |PAR_OPEN exp_bool NOT_EQUAL exp_bool PAR_CLOSE {$$=new_ast_equality_node("!=",$2,$4);}
        ;
str_word:STRING_WORD {$$ = new_ast_symbol_reference_node(yytext);}
        ;
bool_param:BOOLEAN_PARAM {$$ = new_ast_symbol_reference_node(yytext);}
          ;
not:NOT {$$ = new_ast_symbol_reference_node(yytext);}
   ;
exp:exp MORE_EQUAL exp {$$=new_ast_relational_node(">=",$1,$3);}
    |exp LESS_EQUAL exp {$$=new_ast_relational_node("<=",$1,$3);}
    |exp LESS exp {$$=new_ast_relational_node("<",$1,$3);}
    |exp MORE exp {$$=new_ast_relational_node(">",$1,$3);}
    |exp PLUS exp {$$=new_ast_node('+',$1,$3);}
    |exp MINUS exp {$$=new_ast_node('-',$1,$3);}
    |exp MUL exp {$$ = new_ast_node('*',$1,$3);}
    |exp DIVISION exp {$$=new_ast_node('/',$1,$3);}
    |PLUS exp {$$=new_ast_node('+',$2,NULL);}
    |MINUS exp {$$=new_ast_node('-',$2,NULL);}
    |number {$$=$1;}
    |var {$$=$1;} 
    |CHAR_VAL {$$ = new_ast_symbol_reference_node(yytext);}
    |var index {$$ = new_ast_var_index_of_node($1,$2);}
    |PAR_OPEN exp PAR_CLOSE {$$=$2;}
    |value_of {$$=$1;}
    |abs {$$=$1;}
    |address_of {$$=$1;}
    ;
address_of:ADDRESS_OF var {$$ = new_ast_address_of_node('&',$2);}
          |ADDRESS_OF var index {$$ = new_ast_address_of_node('&',new_ast_var_index_of_node($2,$3));}
          |ADDRESS_OF error{yyerror("wrong summoning of value address");return 0;}   /*?????????????????????????????????*/
          ;
index:INDEX_OPEN num_math_exp INDEX_CLOSE {$$ = new_ast_index_original_node($2);}
     |INDEX_OPEN num_math_exp error{yyerror("wrong index"); return 0;}
     |INDEX_OPEN var INDEX_CLOSE {$$ = new_ast_index_original_node($2);}
     ;
value_of:VALUE_OF var {$$ = new_ast_value_of_node('^',$2);}
        |VALUE_OF PAR_OPEN var PLUS num_math_exp PAR_CLOSE {$$ = new_ast_value_of_node('^',new_ast_node('+',$3,$5));}
      //  |VALUE_OF PAR_OPEN num_math_exp PLUS var PAR_CLOSE {$$ = new_ast_value_of_node('+',$3,$5);}
        |VALUE_OF PAR_OPEN var MINUS num_math_exp PAR_CLOSE {$$ = new_ast_value_of_node('^',new_ast_node('-',$3,$5));}
      //  |VALUE_OF PAR_OPEN num_math_exp MINUS var PAR_CLOSE {$$ = new_ast_value_of_node('-',$3,$5);}
        |VALUE_OF error{yyerror("wrong summoning of pointer value");return 0;}
        ;
abs:ABSOLUTE str_word ABSOLUTE {$$ = new_ast_abs_node(0,$2);}
   |ABSOLUTE num_math_exp ABSOLUTE {$$ = new_ast_abs_node(0,$2);}
   |ABSOLUTE PLUS num_math_exp ABSOLUTE {$$ = new_ast_abs_node('+',$3);}
   |ABSOLUTE MINUS num_math_exp ABSOLUTE {$$ = new_ast_abs_node('-',$3);}
   |ABSOLUTE var ABSOLUTE {$$ = new_ast_abs_node(0,$2);}    
   ;
num_math_exp:number {$$=$1;}
            |num_math_exp PLUS num_math_exp {$$=new_ast_node('+',$1,$3);}
            |num_math_exp MINUS num_math_exp {$$=new_ast_node('-',$1,$3);}
            |num_math_exp MUL num_math_exp {$$=new_ast_node('*',$1,$3);}
            |num_math_exp DIVISION num_math_exp {$$=new_ast_node('/',$1,$3);}
            |PAR_OPEN num_math_exp PAR_CLOSE {$$=$2;}
            |error{yyerror("wrong math expression / the type not integer"); return 0;}
            ;
number:INTEGER_DEC {$$=new_ast_number_node(yytext);}
      |INTEGER_ZERO {$$=new_ast_number_node(yytext);}
      |INTEGER_HEX {$$=new_ast_number_node(yytext);}
      |INTEGER_BIN {$$=new_ast_number_node(yytext);}
      |INTEGER_OCTAL {$$=new_ast_number_node(yytext);}
      ;   
%%
#include "lex.yy.c"
main(){
count_tac = 0;
tac_head = NULL;
maincount=0;
mainflag=0;
Error=(char*)malloc(1);
if(Error){
	Error[0]='\0';
}
else{
	printf("Allocation faild\n Program will terimnate now");
	exit(0);
}
	yyparse();
	if(maincount==1&&mainflag==0){
		/*print_symbol_table(tail);*/
		printf("\n%s\n",Error);	
	}
	else
	{
		if(maincount==0)
			Error_Func("No Main Procedure Exists!!");
		if(maincount>1)
			Error_Func("Duplicated Main Procedure!!");
		if(mainflag==1)
			Error_Func("Main Procedure Can't Hold Arguments!!");
		printf("\n%s\n",Error);
	}

while(tac_head->up != NULL) tac_head = tac_head->up;
printf("Tree ADDRESS CODE\n");
while(tac_head->down != NULL){ printf("%d : %s\n",tac_head->num,tac_head->row); tac_head = tac_head->down;}

}
//-------------------------------- new functions ---------------------------------------------
struct ast_node * new_ast_node (int node_type, struct ast_node * left, struct ast_node * right)
{
  	struct ast_node * ast_node = (struct ast_node *)malloc (sizeof (struct ast_node));
        ast_node->type = TYPE_ERROR;
  	ast_node->node_type = node_type;
  	ast_node->left = left;
	ast_node->line=yylineno;
  	ast_node->right = right;
  	return ast_node;
}
struct ast_node * new_ast_relational_node (char* operator, struct ast_node * left, struct ast_node * right)
{
  	struct ast_relational_node * ast_node = (struct ast_relational_node *)malloc (sizeof (struct ast_relational_node));
  	char *newstr = (char*)malloc(sizeof(operator)+1);
  	strcpy(newstr,operator);
  	ast_node->node_type = 'R';
  	ast_node->operator = newstr;
  	ast_node->left = left;
  	ast_node->right = right;
	ast_node->line=yylineno;
        ast_node->type = TYPE_ERROR;  	
	return (struct ast_node *) ast_node;
}
struct ast_node * new_ast_equality_node (char* operator,struct ast_node * left, struct ast_node * right)
{
  	struct ast_equality_node * ast_node = (struct ast_equality_node *)malloc (sizeof (struct ast_equality_node));
  	char *newstr = (char*)malloc(sizeof(operator)+1);
  	strcpy(newstr,operator);
  	ast_node->node_type = 'E';
  	ast_node->operator = newstr;
  	ast_node->left = left;
	ast_node->line=yylineno;
  	ast_node->right = right;
        ast_node->type = TYPE_ERROR;
  	return (struct ast_node *) ast_node;
}
struct ast_node * new_ast_function_node (char* name, struct ast_node * arguments)
{
  	struct ast_function_node * ast_node = (struct ast_function_node *)malloc (sizeof (struct ast_function_node));
  	char *newstr = (char*)malloc(sizeof(name)+1);
  	strcpy(newstr,name);
  	ast_node->node_type = 'F';
  	ast_node->arguments = arguments;
  	ast_node->name = newstr;
	ast_node->line=yylineno;
        ast_node->type = TYPE_ERROR;
  	return (struct ast_node *) ast_node;
}
struct ast_node * new_ast_symbol_reference_node (char* name)
{
  	struct ast_symbol_reference_node * ast_node = (struct ast_symbol_reference_node *)malloc (sizeof (struct ast_symbol_reference_node));
  	char *newstr = (char*)malloc(strlen(name)+1);
  	strcpy(newstr,name);
  	ast_node->node_type = 'S';
  	ast_node->name = newstr;
	//printf("name=%s-----newstr=%s------node->name=%s\n",name,newstr,ast_node->name);
	//ast_node->line=yylineno;
        ast_node->type = TYPE_ERROR;
  	return (struct ast_node *) ast_node;
}
struct ast_node * new_ast_if_node (struct ast_node * condition, struct ast_node * if_branch, struct ast_node * else_branch)
{
  	struct ast_if_node * ast_node = (struct ast_if_node *)malloc (sizeof (struct ast_if_node));
  	ast_node->node_type = 'I';
  	ast_node->condition = condition;
  	ast_node->if_branch = if_branch;
 	ast_node->line=yylineno;
  	ast_node->else_branch = else_branch;  
	ast_node->type=TYPE_ERROR;
  	return (struct ast_node *) ast_node;
}
struct ast_node * new_ast_while_node (struct ast_node * condition, struct ast_node * while_branch)
{
  	struct ast_while_node * ast_node = (struct ast_while_node *)malloc (sizeof (struct ast_while_node));
  	ast_node->node_type = 'W';
  	ast_node->condition = condition;
	ast_node->line=yylineno;
  	ast_node->while_branch = while_branch;
	ast_node->type=TYPE_ERROR;
  	return (struct ast_node *) ast_node;
}
struct ast_node * new_ast_assignment_node (struct ast_node * name, struct ast_node * value)
{
  	struct ast_assignment_node * ast_node = (struct ast_assignment_node *)malloc (sizeof (struct ast_assignment_node));
  	ast_node->node_type = 'A';
  	ast_node->name = name;
  	ast_node->value = value;
	ast_node->type=TYPE_ERROR;
	ast_node->line=yylineno;
  	return (struct ast_node *) ast_node;
}
struct ast_node * new_ast_number_node (char* value)
{
  	struct ast_number_node * ast_node = (struct ast_number_node *)malloc (sizeof (struct ast_number_node));
  	char *newstr = (char*)malloc(sizeof(value)+1);  
  	strcpy(newstr,value);  
  	ast_node->node_type = 'N';
  	ast_node->value = newstr;
	ast_node->type=TYPE_INTEGER;
  	return (struct ast_node *) ast_node;
}
struct ast_node * new_ast_block_node(struct ast_node * commands)
{
	struct ast_block_node * ast_node = (struct ast_block_node *)malloc(sizeof(struct ast_block_node));
	ast_node->node_type = 'B';
	ast_node->commands = commands;
	ast_node->type=TYPE_ERROR;
	return (struct ast_node *) ast_node;
}
struct ast_node * new_ast_procedure_node(struct ast_node * name, struct ast_node * r_type, struct ast_node * args, struct ast_node * f_block)
{
	struct ast_procedure_node * ast_node = (struct ast_procedure_node *)malloc(sizeof(struct ast_procedure_node));
	if(strcmp(((struct ast_symbol_reference_node*)name)->name,"Main")==0)
	{
		maincount++;
		if(args!=NULL)
			mainflag=1;	
	}
	ast_node->line=yylineno;
	ast_node->node_type = 'P';
	ast_node->name = name;
	ast_node->return_type = r_type;
	ast_node->args = args;
	ast_node->funcblock = f_block;
	ast_node->type=TYPE_ERROR;
	return (struct ast_node *) ast_node;
}
struct ast_node * new_ast_return_node(struct ast_node *left)
{
	struct ast_return_node * ast_node = (struct ast_return_node *)malloc(sizeof(struct ast_return_node));
	ast_node->node_type = 'Z';
	ast_node->left = left;
        ast_node->type = TYPE_ERROR;
	return (struct ast_node *) ast_node;
}
struct ast_node * new_ast_func_block_node(struct ast_node *left, struct ast_node *right)
{
	struct ast_func_block_node * ast_node = (struct ast_func_block_node *)malloc(sizeof(struct ast_func_block_node));
	ast_node->node_type = 'Y';
	ast_node->commands = left;
	ast_node->return_stm = right;
        ast_node->type = TYPE_ERROR;
	return (struct ast_node *) ast_node;
}
struct ast_node* new_string_list(struct ast_node* node,struct ast_node* next)
{
	if(!node)
		return NULL;
	struct string_list* ast_node=(struct string_list*)malloc(sizeof(struct string_list));
	ast_node->node=node;
	ast_node->next=next;
	return (struct ast_node *) ast_node;
}
struct ast_node * new_ast_def(struct ast_node* vars,struct ast_node* type)
{
	struct ast_def * ast_node=(struct ast_def *)malloc(sizeof(struct ast_def));
	ast_node->node_type='D';
	ast_node->vars=vars;
	ast_node->type2=type;
	ast_node->type=TYPE_ERROR;
	return (struct ast_node*)ast_node;
}
struct ast_node * new_ast_address_of_node(int operator,struct ast_node * name)
{
	struct ast_address_of_node * ast_node=(struct ast_address_of_node*)malloc(sizeof(struct ast_address_of_node));
	ast_node->node_type='C';
	ast_node->operator=operator;
	ast_node->name=name;
        ast_node->type = TYPE_ERROR;
	return (struct ast_node*)ast_node;
}
struct ast_node * new_ast_def_index_of_node(struct ast_node * name)
{
	struct ast_def_index_of_node * ast_node=(struct ast_def_index_of_node*)malloc(sizeof(struct ast_def_index_of_node));
	ast_node->node_type='G';
	strcpy(ast_node->type2,"string");
        ast_node->type = TYPE_ERROR;
	ast_node->name=name;
	return (struct ast_node*)ast_node;
}
struct ast_node * new_ast_var_index_of_node(struct ast_node * name, struct ast_node * value)
{
	struct ast_var_index_of_node * ast_node=(struct ast_var_index_of_node *)malloc(sizeof(struct ast_var_index_of_node));
	ast_node->node_type='H';
	ast_node->name=name;
	ast_node->value=value;
	//ast_node->line=yylineno;
        ast_node->type = TYPE_ERROR;
	return (struct ast_node*)ast_node;
}
struct ast_node * new_ast_index_original_node(struct ast_node * name)
{
	struct ast_index_original_node * ast_node=(struct ast_index_original_node *)malloc(sizeof(struct ast_index_original_node));
	ast_node->node_type='O';
	ast_node->name=name;
        ast_node->type = TYPE_ERROR;
	return (struct ast_node*)ast_node;
}
struct ast_node * new_ast_abs_node(int operator,struct ast_node * name)
{
	struct ast_abs_node * ast_node=(struct ast_abs_node *)malloc(sizeof(struct ast_abs_node));
	ast_node->node_type='J';
	ast_node->operator = operator;
	ast_node->name=name;
        ast_node->type = TYPE_ERROR;
	return (struct ast_node*)ast_node;
}
struct ast_node * new_ast_value_of_node(int operator,struct ast_node * left)
{
	struct ast_value_of_node * ast_node=(struct ast_value_of_node *)malloc(sizeof(struct ast_value_of_node));
	ast_node->node_type='V';
	ast_node->operator = operator;
        ast_node->type = TYPE_ERROR;
	ast_node->left=left;
	return (struct ast_node*)ast_node;
}
//--------------------------------- symbol table new node --------------------------
// struct symbol_node * new_symbol_node(char*name,char* value,char* type,struct symbol_node* next,struct symbol_node* next_block,struct symbol_node* prev)
// {	
	// struct symbol_node* temp= (struct symbol_node*)malloc(sizeof(struct symbol_node));
	// char *newstr = (char*)malloc(sizeof(name)+1);  
  	// strcpy(newstr,name);  
	// temp->name=newstr;
	// char *newstr1 = (char*)malloc(sizeof(value)+1);  
  	// strcpy(newstr1,value);
	// temp->value=newstr1;
	// char *newstr2 = (char*)malloc(sizeof(type)+1);  
  	// strcpy(newstr2,type);
	// temp->type=newstr2;
	// temp->next=next;
	// temp->next_block=next_block;
	// temp->prev=prev;
	// return temp;
// }





void print_tac_tree (struct ast_node * ast_tree)
{ 
  	if (!ast_tree) 
		return;

  	switch (ast_tree->node_type)
  	{    		
		case '+':    
    		case '-':     
    		case '*':     
    		case '/':       
			{
				if(ast_tree->left)
				{
         	 			print_tac_tree (ast_tree->left);
				}
				if(ast_tree->right)
				{
	  				print_tac_tree (ast_tree->right);
				}
                                struct tac_node * temp_tac = (struct tac_node*)malloc(sizeof(struct tac_node));
                                count_tac++;
                                int i = 0;
                                char* tstr = mkrndstr();
                                while(str_stack[i] != NULL){
                                        i++;
                                }

				temp_tac->row = (char*)malloc(sizeof(str_stack[i-1])+sizeof(str_stack[i-2])+3+sizeof(tstr));
                                strncpy(temp_tac->row,tstr,strlen(tstr));
                                temp_tac->row[strlen(tstr)]= '=';
                                strncpy(temp_tac->row+strlen(tstr)+1,str_stack[i-2],strlen(str_stack[i-2]));
                                temp_tac->row[strlen(str_stack[i-2])+strlen(tstr)+1]= ast_tree->node_type;
                                strncpy(temp_tac->row+strlen(str_stack[i-2])+strlen(tstr)+2,str_stack[i-1],strlen(str_stack[i-1]));
                                temp_tac->row[strlen(str_stack[i-2])+strlen(str_stack[i-1])+strlen(tstr)+2]='\0';
                                str_stack[i-1] = NULL;
                                str_stack[i-2] = NULL;
                                temp_tac->num = count_tac;
                                //printf("%s\n",temp_tac->row);

                                if(tac_head == NULL){
                                        tac_head = temp_tac;
                                        tac_head->up = NULL;
                                        tac_head->down = NULL;
                                        //printf("Headddd ---- %s\n",tac_head->row);
                                }
                                else{
                                        temp_tac->up = tac_head;
                                        tac_head->down = temp_tac;
                                        temp_tac->down = NULL;
                                        tac_head = temp_tac;
                               }

                                str_stack[i-2] = tstr;
			}
			break;
    		case 'L':
			{
				if(ast_tree->left)
				{
          				print_tac_tree (ast_tree->left);
				}
				if(ast_tree->right)
	  				print_tac_tree (ast_tree->right);
        		}
        		break;
    		case 'B':
			{
				struct ast_block_node * node = (struct ast_block_node *) ast_tree;
				if(node->commands)
				{
					print_tac_tree (node->commands);	
				}		
			}
        		break;
    		case 'P':
			{
				struct ast_procedure_node * node = (struct ast_procedure_node *) ast_tree;                              
				struct tac_node * temp_tac = (struct tac_node*)malloc(sizeof(struct tac_node));
                                count_tac++;
				char* VarName=((struct ast_symbol_reference_node*)node->name)->name;
				temp_tac->row = (char*)malloc(sizeof(VarName)+2);
                                strncpy(temp_tac->row,VarName,strlen(VarName));
                                strncpy(temp_tac->row+strlen(VarName),":",1);
                                temp_tac->row[strlen(VarName)+2]='\0';
                                temp_tac->num = count_tac;
                                //printf("%s\n",temp_tac->row);

                                if(tac_head == NULL){
                                        tac_head = temp_tac;
                                        tac_head->up = NULL;
                                        tac_head->down = NULL;
                                        //printf("Headddd ---- %s\n",tac_head->row);
                                }
                                else{
                                        temp_tac->up = tac_head;
                                        tac_head->down = temp_tac;
                                        temp_tac->down = NULL;
                                        tac_head=temp_tac;
                                }
				if(node->return_type)
				{
				
	    				print_tac_tree (node->return_type);
				}
				if(node->funcblock)
				{
	    				print_tac_tree (node->funcblock);
                                }
			}
        		break;
    		case 'Z':
			{
				struct ast_return_node * node = (struct ast_return_node *) ast_tree;
                                
				if(node->left)
					print_tac_tree (node->left);
                                
			}
        		break;
    		case 'Y':
			{
				struct ast_func_block_node * node = (struct ast_func_block_node *) ast_tree;
				if(node->commands)
				{
					print_tac_tree (node->commands);
				}
				if(node->return_stm)
				{
                                        
					print_tac_tree (node->return_stm);
                                        struct tac_node * temp_tac = (struct tac_node*)malloc(sizeof(struct tac_node));
                                        count_tac++;
                                    
                                        int i = 0;
                                        while(str_stack[i] != 0){
                                                i++;
                                        }
  				        temp_tac->row = (char*)malloc(7+strlen(str_stack[i-1]));
                                        strncpy(temp_tac->row,"RETURN",strlen("RETURN"));
                                        temp_tac->row[6]=' ';
                                        strncpy(temp_tac->row+7,str_stack[i-1],strlen(str_stack[i-1]));
                                        
                                        temp_tac->row[7+strlen(str_stack[i-1])]='\0';
                                        str_stack[i-1] = NULL;
                                        temp_tac->num = count_tac;
                                        //printf("%s\n",temp_tac->row);

                                        if(tac_head == NULL){
                                                tac_head = temp_tac;
                                                tac_head->up = NULL;
                                                tac_head->down = NULL;
                                                //printf("Headddd ---- %s\n",tac_head->row);
                                        }
                                        else{
                                                temp_tac->up = tac_head;
                                                tac_head->down = temp_tac;
                                                temp_tac->down = NULL;
                                                tac_head = temp_tac;
                                        }



                                        struct tac_node * tac = (struct tac_node*)malloc(sizeof(struct tac_node));
                                        count_tac++;
  				        tac->row = (char*)malloc(8);
                                        strncpy(tac->row,"EndFunc",7);
                                        
                                        tac->row[7]='\0';
                                        tac->num = count_tac;
                                        //printf("%s\n",tac->row);

                                        tac->up = tac_head;
                                        tac_head->down = tac;
                                        tac->down = NULL;
                                        tac_head = tac;
                                        
				}
			}
        		break;
    		case 'S':  
			{
				struct ast_symbol_reference_node * node = (struct ast_symbol_reference_node *) ast_tree;

                                int i = 0;
                                while(str_stack[i] != NULL){
                                        i++;
                                }
                                str_stack[i] = node->name;
			}
			break;
    		case 'N':  //number
			{
                                
				struct ast_number_node * node = (struct ast_number_node *) ast_tree;
                                struct tac_node * temp_tac = (struct tac_node*)malloc(sizeof(struct tac_node));
                                count_tac++;
				char* VarName=node->value;
                                char* RanName = mkrndstr();
				temp_tac->row = (char*)malloc(sizeof(VarName)+sizeof(RanName)+2);
                                strncpy(temp_tac->row,RanName,strlen(RanName));
                                temp_tac->row[strlen(RanName)]='=';
                                strncpy(temp_tac->row+strlen(RanName)+1,VarName,strlen(VarName));
                                temp_tac->row[strlen(VarName)+strlen(RanName)+1]='\0';
                                temp_tac->num = count_tac;
                                //printf("%s\n",temp_tac->row);

                                if(tac_head == NULL){
                                        tac_head = temp_tac;
                                        tac_head->up = NULL;
                                        tac_head->down = NULL;
                                        //printf("Headddd ---- %s\n",tac_head->row);
                                }
                                else{
                                        temp_tac->up = tac_head;
                                        tac_head->down = temp_tac;
                                        temp_tac->down = NULL;
                                        tac_head = temp_tac;
                                }
                                int i = 0;
                                while(str_stack[i] != 0){
                                        i++;
                                }
                                str_stack[i] = RanName;
			}
      			break;
    		case 'R': //relational
      			{
        			struct ast_relational_node * node = (struct ast_relational_node *) ast_tree;
				
				if(node->left)
				{
          				print_tac_tree (node->left);
				}
				if(node->right)
				{
	  				print_tac_tree (node->right);
				}
                                struct tac_node * temp_tac = (struct tac_node*)malloc(sizeof(struct tac_node));
                                count_tac++;
                                int i = 0;
                                char* tstr = mkrndstr();
                                while(str_stack[i] != NULL){
                                        i++;
                                }

				temp_tac->row = (char*)malloc(sizeof(str_stack[i-1])+sizeof(str_stack[i-2])+3+sizeof(tstr));
                                strncpy(temp_tac->row,tstr,strlen(tstr));
                                temp_tac->row[strlen(tstr)]= '=';
                                strncpy(temp_tac->row+strlen(tstr)+1,str_stack[i-2],strlen(str_stack[i-2]));
                                strncpy(temp_tac->row+strlen(str_stack[i-2])+strlen(tstr)+1,node->operator,strlen(node->operator));
                                strncpy(temp_tac->row+strlen(str_stack[i-2])+strlen(tstr)+1+strlen(node->operator),str_stack[i-1],strlen(str_stack[i-1]));
                                temp_tac->row[strlen(str_stack[i-2])+strlen(str_stack[i-1])+strlen(tstr)+1+strlen(node->operator)]='\0';
                                str_stack[i-1] = NULL;
                                str_stack[i-2] = NULL;
                                temp_tac->num = count_tac;
                                //printf("%s\n",temp_tac->row);

                                if(tac_head == NULL){
                                        tac_head = temp_tac;
                                        tac_head->up = NULL;
                                        tac_head->down = NULL;
                                        //printf("Headddd ---- %s\n",tac_head->row);
                                }
                                else{
                                        temp_tac->up = tac_head;
                                        tac_head->down = temp_tac;
                                        temp_tac->down = NULL;
                                        tac_head = temp_tac;
                               }

                                str_stack[i-2] = tstr;
      			}
      			break;
    		case 'E': //equality
      			{
				struct ast_equality_node * node = (struct ast_equality_node *) ast_tree;
				//printf("%s ",node->operator);
				if(node->left)
				{
          				print_tac_tree (node->left);
				}
				if(node->right)
				{
	  				print_tac_tree (node->right);
				}
                                struct tac_node * temp_tac = (struct tac_node*)malloc(sizeof(struct tac_node));
                                count_tac++;
                                int i = 0;
                                char* tstr = mkrndstr();
                                while(str_stack[i] != NULL){
                                        i++;
                                }

				temp_tac->row = (char*)malloc(sizeof(str_stack[i-1])+sizeof(str_stack[i-2])+3+sizeof(tstr));
                                strncpy(temp_tac->row,tstr,strlen(tstr));
                                temp_tac->row[strlen(tstr)]= '=';
                                strncpy(temp_tac->row+strlen(tstr)+1,str_stack[i-2],strlen(str_stack[i-2]));
                                strncpy(temp_tac->row+strlen(str_stack[i-2])+strlen(tstr)+1,node->operator,strlen(node->operator));
                                strncpy(temp_tac->row+strlen(str_stack[i-2])+strlen(tstr)+1+strlen(node->operator),str_stack[i-1],strlen(str_stack[i-1]));
                                temp_tac->row[strlen(str_stack[i-2])+strlen(str_stack[i-1])+strlen(tstr)+1+strlen(node->operator)]='\0';
                                str_stack[i-1] = NULL;
                                str_stack[i-2] = NULL;
                                temp_tac->num = count_tac;
                                //printf("%s\n",temp_tac->row);

                                if(tac_head == NULL){
                                        tac_head = temp_tac;
                                        tac_head->up = NULL;
                                        tac_head->down = NULL;
                                        //printf("Headddd ---- %s\n",tac_head->row);
                                }
                                else{
                                        temp_tac->up = tac_head;
                                        tac_head->down = temp_tac;
                                        temp_tac->down = NULL;
                                        tac_head = temp_tac;
                               }

                                str_stack[i-2] = tstr;
      			}
      			break;
    		case 'A': 
      			{
        			struct ast_assignment_node * node = (struct ast_assignment_node *) ast_tree;
        			print_tac_tree (node->name);
                                int i = 0;
                                while(str_stack[i] != 0){
                                        i++;
                                }
                                char* VarName=str_stack[i-1];
                                str_stack[i-1] = NULL;
        			print_tac_tree (node->value);
                                i = 0;
                                while(str_stack[i] != 0){
                                        i++;
                                }
                                char* VarName2=str_stack[i-1];
                                str_stack[i-1] = NULL;			
                                struct tac_node * temp_tac = (struct tac_node*)malloc(sizeof(struct tac_node));
                                count_tac++;
				

				temp_tac->row = (char*)malloc(sizeof(VarName)+sizeof(VarName2)+1);
                                strncpy(temp_tac->row,VarName,strlen(VarName));
                                temp_tac->row[strlen(VarName)]='=';
                                strncpy(temp_tac->row+strlen(VarName)+1,VarName2,strlen(VarName2));
                                temp_tac->row[strlen(VarName2)+strlen(VarName)+1]='\0';
                                temp_tac->num = count_tac;
                                //printf("%s\n",temp_tac->row);

                                if(tac_head == NULL){
                                        tac_head = temp_tac;
                                        tac_head->up = NULL;
                                        tac_head->down = NULL;
                                        //printf("Headddd ---- %s\n",tac_head->row);
                                }
                                else{
                                        temp_tac->up = tac_head;
                                        tac_head->down = temp_tac;
                                        temp_tac->down = NULL;
                                        tac_head = temp_tac;
                                }
                                
      			}
      			break;
    		case 'I':
      			{
				struct ast_if_node * node = (struct ast_if_node *) ast_tree;
				if(node->condition)
				{
   	  				print_tac_tree (node->condition);

                                }



                                struct tac_node * temp_tac = (struct tac_node*)malloc(sizeof(struct tac_node));
                                count_tac++;
                                int ct2 = count_tac;
                                int q = 0;
                                while(str_stack[q] != 0){
                                        q++;
                                }
                                int len2 = strlen(str_stack[q-1]);




                                temp_tac->row= (char*)malloc(sizeof(str_stack[q-1])+20);
                                strncpy(temp_tac->row,"IFZ ",4);
                                strncpy(temp_tac->row+4,str_stack[q-1],strlen(str_stack[q-1]));
                                strncpy(temp_tac->row+strlen(str_stack[q-1])+4," GOTO           ",16);
                                temp_tac->row[strlen(str_stack[q-1])+20]='\0';
                                str_stack[q-1] = NULL;
                                temp_tac->num = count_tac;
                                //printf("%s\n",temp_tac->row);

                                if(tac_head == NULL){
                                        tac_head = temp_tac;
                                        tac_head->up = NULL;
                                        tac_head->down = NULL;
                                        //printf("Headddd ---- %s\n",tac_head->row);
                                }
                                else{
                                        temp_tac->up = tac_head;
                                        tac_head->down = temp_tac;
                                        temp_tac->down = NULL;
                                        tac_head = temp_tac;
                               }


/*--------------------------------------------------------------------------------------------*/

				if(node->if_branch)
					print_tac_tree (node->if_branch);


                                struct tac_node * temp_tac2 = (struct tac_node*)malloc(sizeof(struct tac_node));
                                count_tac++;
                                int ct22 = count_tac;

                                temp_tac2->row = (char*)malloc(15);
                                strncpy(temp_tac2->row,"GOTO           ",15);
                                temp_tac2->row[15]='\0';
                                temp_tac2->num = count_tac;
                                //printf("%s\n",temp_tac2->row);

                                if(tac_head == NULL){
                                        tac_head = temp_tac2;
                                        tac_head->up = NULL;
                                        tac_head->down = NULL;
                                        //printf("Headddd ---- %s\n",tac_head->row);
                                }
                                else{
                                        temp_tac2->up = tac_head;
                                        tac_head->down = temp_tac2;
                                        temp_tac2->down = NULL;
                                        tac_head = temp_tac2;
                               }


/*/////////////////////////////////////////////////////////////////////////////////////////*/
                                struct tac_node * thelp = tac_head;
                                while(thelp->num != ct2){
                                        thelp = thelp->up;
                                }

                                int ct = count_tac+1;
                                int len = 0,rem,j=0;
                                char rr[15];
                                while(ct != 0 ){
                                       len++;
                                       ct/=10;
                                }
                                ct = count_tac+1;
                                for(j=0;j<len;j++){
                                       rem = ct%10;
                                       ct=ct/10;
                                       rr[len-(j+1)]= rem +'0';
                                }
                                rr[len]='\0';
                                for(j=0;j<len;j++){
                                       thelp->row[len2+10+j] = rr[j];
                                }
                                //printf("tikunnnn   %s\n",thelp->row);


/*-------------------------------------------------------------------------------------------------*/
				
				if (node->else_branch)
        			{
        				print_tac_tree (node->else_branch);
				}
/*/////////////////////////////////////////////////////////////////////////////////////////*/
                                thelp = tac_head;
                                while(thelp->num != ct22){
                                        thelp = thelp->up;
                                }

                                ct = count_tac+1;
                                len = 0;
                                while(ct != 0 ){
                                       len++;
                                       ct/=10;
                                }
                                ct = count_tac+1;
                                for(j=0;j<len;j++){
                                       rem = ct%10;
                                       ct=ct/10;
                                       rr[len-(j+1)]= rem +'0';
                                }
                                rr[len]='\0';
                                for(j=0;j<len;j++){
                                       thelp->row[6+j] = rr[j];
                                }
                                //printf("tikunnnn   %s\n",thelp->row);

      			}
      			break;
    		case 'W':
      			{
				struct ast_while_node * node = (struct ast_while_node *) ast_tree;

                               
				if(node->condition)
				{
   	  				print_tac_tree (node->condition);
                                }
/*-----------------------------------------------------------------------------------------------*/
				struct tac_node * temp_tac = (struct tac_node*)malloc(sizeof(struct tac_node));
                                char rr[5];
                                int len = 0;
                                int ct = count_tac;

                                while(ct != 0 ){
                                       len++;
                                       ct/=10;
                                }

                                int j,rem;
                                ct = count_tac;
                                for(j=0;j<len;j++){
                                       rem = ct%10;
                                       ct=ct/10;
                                       rr[len-(j+1)]=rem +'0';
                                     
                                }
                                rr[len]='\0';
                                char* temp_t = (char*)malloc(6+sizeof(rr));
                                strncpy(temp_t,"GOTO",4);
                                temp_t[4]=' ';
                                strncpy(temp_t+5,rr,sizeof(rr));
                                temp_t[5+sizeof(rr)]='\0';
/*---------------------------------------------2--------------------------------------------------*/
                                struct tac_node * temp_tac2 = (struct tac_node*)malloc(sizeof(struct tac_node));
                                count_tac++;
                                int ct2 = count_tac;
                                int q = 0;
                                while(str_stack[q] != 0){
                                        q++;
                                }
                                int len2 = strlen(str_stack[q-1]);




                                temp_tac2->row = (char*)malloc(sizeof(str_stack[q-1])+20);
                                strncpy(temp_tac2->row,"IFZ ",4);
                                strncpy(temp_tac2->row+4,str_stack[q-1],strlen(str_stack[q-1]));
                                strncpy(temp_tac2->row+strlen(str_stack[q-1])+4," GOTO           ",16);
                                temp_tac2->row[strlen(str_stack[q-1])+20]='\0';
                                str_stack[q-1] = NULL;
                                temp_tac2->num = count_tac;
                                //printf("%s\n",temp_tac2->row);

                                if(tac_head == NULL){
                                        tac_head = temp_tac2;
                                        tac_head->up = NULL;
                                        tac_head->down = NULL;
                                        //printf("Headddd ---- %s\n",tac_head->row);
                                }
                                else{
                                        temp_tac2->up = tac_head;
                                        tac_head->down = temp_tac2;
                                        temp_tac2->down = NULL;
                                        tac_head = temp_tac2;
                               }





/*-----------------------------------------------------------------------------------------------*/
        			if (node->while_branch)
        			{
          				print_tac_tree (node->while_branch);
				}

                                count_tac++;
                                temp_tac->row = temp_t;
                                temp_tac->num = count_tac;
                                //printf("%s\n",temp_tac->row);

                                if(tac_head == NULL){
                                        tac_head = temp_tac;
                                        tac_head->up = NULL;
                                        tac_head->down = NULL;
                                        //printf("Headddd ---- %s\n",tac_head->row);
                                }
                                else{
                                        temp_tac->up = tac_head;
                                        tac_head->down = temp_tac;
                                        temp_tac->down = NULL;
                                        tac_head=temp_tac;
                                }
/*////////////////////////////////////////////////////////////////////////////////////////////////*/
                                struct tac_node * thelp = tac_head;
                                while(thelp->num != ct2){
                                        thelp = thelp->up;
                                }

                                ct = count_tac+1;
                                len = 0;
                                while(ct != 0 ){
                                       len++;
                                       ct/=10;
                                }
                                ct = count_tac+1;
                                for(j=0;j<len;j++){
                                       rem = ct%10;
                                       ct=ct/10;
                                       rr[len-(j+1)]=rem +'0';
                                }
                                rr[len]='\0';
                                for(j=0;j<len;j++){
                                       thelp->row[len2+10+j] = rr[j];
                                }
                                //printf("%s\n",thelp->row);
/*--------------------------------------------------------------------------------------------------*/
      			}
      			break;
    		case 'F':
      			{
				struct ast_function_node * node = (struct ast_function_node *) ast_tree;
       				//printf("%s ",node->name);
				char* VarName= (char*)malloc(sizeof(node->name)+7);
                                strncpy(VarName,"LCALL ",6);
                                strncpy(VarName+6,node->name,strlen(node->name));
                                VarName[strlen(node->name)+6]='\0';
                                int i = 0;
                                while(str_stack[i] != NULL){
                                        i++;
                                }
                                str_stack[i] = VarName;
      			}
      			break;
    		case'D':
      			{
				//printf("Def ");						
       			}
       			break;
    		case 'C':
      			{		
        			struct ast_address_of_node * node = (struct ast_address_of_node *) ast_tree;
        			if (node->name)
        			{
	  				//if(node->operator == '&')
	      					//printf("%c ",node->operator);
          				print_tac_tree(node->name);
        			}
      			}
      			break;
    		case 'G':
      			{
        			struct ast_def_index_of_node * node = (struct ast_def_index_of_node *) ast_tree;
        			if (node->name)
  			      	{
          				print_tac_tree(node->name);
        			}
      			}
      			break;
   		case 'H':
      			{
        			struct ast_var_index_of_node * node = (struct ast_var_index_of_node *) ast_tree;
        			if (node->name)
        			{
          				print_tac_tree(node->name);		
        			}
        			if (node->value)
        			{
	  				print_tac_tree(node->value);
        			}

                                struct tac_node * tt = (struct tac_node*)malloc(sizeof(struct tac_node));
                                count_tac++;
                                int q = 0;
                                while(str_stack[q] != 0){
                                        q++;
                                }
                                char* hname = mkrndstr();
                                tt->row = (char*)malloc(3+sizeof(hname));
                                strncpy(tt->row,hname,strlen(hname));
                                tt->row[strlen(hname)]='=';
                                tt->row[strlen(hname)+1]='4';
                                
                                tt->row[strlen(hname)+2]='\0';
                                str_stack[q] = hname;
                                tt->num = count_tac;
                                //printf("%s\n",tt->row);

                                if(tac_head == NULL){
                                        tac_head = tt;
                                        tac_head->up = NULL;
                                        tac_head->down = NULL;
                                        //printf("Headddd ---- %s\n",tac_head->row);
                                }
                                else{
                                        tt->up = tac_head;
                                        tac_head->down = tt;
                                        tt->down = NULL;
                                        tac_head = tt;
                               }

/*---------------------------------------------------------------------------------------------*/
                                struct tac_node * tt2 = (struct tac_node*)malloc(sizeof(struct tac_node));
                                count_tac++;

                                hname = mkrndstr();
                                tt2->row = (char*)malloc(sizeof(str_stack[q])+sizeof(str_stack[q-1])+3+sizeof(hname));
                                strncpy(tt2->row,hname,strlen(hname));
                                tt2->row[strlen(hname)]='=';
                                strncpy(tt2->row+strlen(hname)+1,str_stack[q-1],strlen(str_stack[q-1]));
                                tt2->row[strlen(hname)+1+strlen(str_stack[q-1])]='*';
                                strncpy(tt2->row+strlen(hname)+2+strlen(str_stack[q-1]),str_stack[q],strlen(str_stack[q]));
                                tt2->row[strlen(hname)+2+strlen(str_stack[q-1])+strlen(str_stack[q])]='\0';
                                str_stack[q] = NULL;
                                str_stack[q-1] = hname;
                                tt2->num = count_tac;
                                //printf("%s\n",tt2->row);

                                if(tac_head == NULL){
                                        tac_head = tt2;
                                        tac_head->up = NULL;
                                        tac_head->down = NULL;
                                        //printf("Headddd ---- %s\n",tt2->row);
                                }
                                else{
                                        tt2->up = tac_head;
                                        tac_head->down = tt2;
                                        tt2->down = NULL;
                                        tac_head = tt2;
                               }
/*----------------------------------------------------------------------------------------------*/
                                struct tac_node * tt1 = (struct tac_node*)malloc(sizeof(struct tac_node));
                                count_tac++;

                                hname = mkrndstr();
                                tt1->row = (char*)malloc(sizeof(str_stack[q-2])+sizeof(str_stack[q-1])+3+sizeof(hname));
                                strncpy(tt1->row,hname,strlen(hname));
                                tt1->row[strlen(hname)]='=';
                                strncpy(tt1->row+strlen(hname)+1,str_stack[q-2],strlen(str_stack[q-2]));
                                tt1->row[strlen(hname)+1+strlen(str_stack[q-2])]='+';
                                strncpy(tt1->row+strlen(hname)+2+strlen(str_stack[q-2]),str_stack[q-1],strlen(str_stack[q-1]));
                                tt1->row[strlen(hname)+2+strlen(str_stack[q-1])+strlen(str_stack[q-2])]='\0';
                                str_stack[q-1] = NULL;
                                str_stack[q-2] = hname;
                                tt1->num = count_tac;
                                //printf("%s\n",tt1->row);

                                if(tac_head == NULL){
                                        tac_head = tt1;
                                        tac_head->up = NULL;
                                        tac_head->down = NULL;
                                        //printf("Headddd ---- %s\n",tt1->row);
                                }
                                else{
                                        tt1->up = tac_head;
                                        tac_head->down = tt1;
                                        tt1->down = NULL;
                                        tac_head = tt1;
                               }
/*-------------------------------------------------------------------------------------------*/
                               int i = 0;
                                while(str_stack[i] != NULL){
                                        i++;
                                }
				char* new = (char*)malloc(sizeof(str_stack[i-1])+4);
                                strncpy(new,"*(",2);
                                strncpy(new+2,str_stack[i-1],strlen(str_stack[i-1]));
                                strncpy(new+strlen(str_stack[i-1])+2,")",1);
                                new[strlen(str_stack[i-1])+3]='\0';
                                str_stack[i-1] = new;
      			}
      			break;
    		case 'O':
      			{
        			struct ast_index_original_node * node = (struct ast_index_original_node *) ast_tree;
        			if (node->name)
        			{
           				print_tac_tree(node->name);
        			}
      			}
      			break;
    		case 'J':
      			{
        			struct ast_abs_node * node = (struct ast_abs_node *) ast_tree;
        			if (node->name)
        			{
	   				//if(node->operator == '-')
					//	printf("-");
           				print_tac_tree(node->name);
        			}
                                int i = 0;
                                while(str_stack[i] != NULL){
                                        i++;
                                }
                                char* VarName = str_stack[i-1];

				char* new = (char*)malloc(sizeof(VarName)+3);
                                new[0]='|';
                                strncpy(new+1,VarName,strlen(VarName));
                                new[strlen(VarName)+1]='|';
                                new[strlen(VarName)+2]='\0';
                                str_stack[i-1] = new;
      			
      			}
      			break;
    		case 'V':
      			{
        			struct ast_value_of_node * node = (struct ast_value_of_node *) ast_tree;
        			if (node->left)
        			{
          				print_tac_tree(node->left);
        			}
                                int i = 0;
                                while(str_stack[i] != NULL){
                                        i++;
                                }
                                char* VarName = str_stack[i-1];

				char* new = (char*)malloc(sizeof(VarName)+4);
                                strncpy(new,"*(",2);
                                strncpy(new+2,VarName,strlen(VarName));
                                strncpy(new+strlen(VarName)+2,")",1);
                                new[strlen(VarName)+3]='\0';
                                str_stack[i-1] = new;
      			}
      			break;
    		default:
      			printf ("Unknown node!\n");
  	}
}










void print_ast_tree (struct ast_node * ast_tree,int level)
{
	char B;
  	int i=0; 
  	if (!ast_tree) 
		return;
  	if(ast_tree->node_type!='L'&&ast_tree->node_type!='O')
	{
		if(ast_tree->node_type=='S' ||ast_tree->node_type=='V'||ast_tree->node_type=='C'||ast_tree->node_type=='N')
		{
			//for(i=0;i<level+1;i++)
			//	printf("  ");
		}
		else
		{
			printf("\n");
  			for(i=0;i<level+1;i++)
  				printf("  ");
			printf("(");
		}
	}
	else
	{
		--level;
	}
  	switch (ast_tree->node_type)
  	{    		
		case '+': 
    		case '-': 
    		case '*': 
    		case '/': 
			{
				printf("%c ",ast_tree->node_type);
				Type type1=TYPE_ERROR,type2=TYPE_ERROR;
				if(ast_tree->left)
				{
         	 			print_ast_tree (ast_tree->left,level+1);
					type1=ast_tree->left->type;
				}
				if(ast_tree->right)
				{
	  				print_ast_tree (ast_tree->right,level+1);
					type2=ast_tree->right->type;
				}
				if(type1==type2 && type1==TYPE_INTEGER)
				{
					ast_tree->type=type1;
				}
				else 
				{
					ast_tree->type=TYPE_ERROR;
					char* errorstring;						
					B=ast_tree->node_type;
					errorstring="Left and right types of operator '";
					errorstring=strcatt(errorstring,&B);
					errorstring=strcatt(errorstring,"' are not suitable! In Line: ");
					Error_Func_line(errorstring, ast_tree->line);
				}
			}
			break;
    		case 'L': //struct ast_node
			{//printf("{L}");
				if(ast_tree->left)
				{
          				print_ast_tree (ast_tree->left,level+1);
				}
				if(ast_tree->right)
	  				print_ast_tree (ast_tree->right,level+1);
        		}
        		break;
    		case 'B':
			{
				printf("Block ");
				insert_var(ast_tree,NULL,3);
				struct ast_block_node * node = (struct ast_block_node *) ast_tree;
				if(node->commands)
				{
					print_ast_tree (node->commands,level+1);	
				}
				printf("\n");
				while(tail->prev!=NULL){
					tail=tail->prev;
				}
				tail=tail->top;			
			}
        		break;
    		case 'P':
			{
				printf("Procedure ");
				struct ast_procedure_node * node = (struct ast_procedure_node *) ast_tree;
				if(get_symbal_node(((struct ast_symbol_reference_node*)node->name)->name,1)!=NULL)//if the procedure already defined
				{
					char* VarName=((struct ast_symbol_reference_node*)node->name)->name;
					char* errorstring;
					errorstring="Duplicated Procedure Name: ";
					errorstring=strcatt(errorstring,VarName);
					errorstring=strcatt(errorstring," In Line: ");
					Error_Func_line(errorstring, node->line);
					node->type=TYPE_ERROR;
				}
				if(node->name)
				{
					insert_var(node->name,node->return_type,1);
	    				print_ast_tree (node->name,level+1);
				}
				symbal_node* temp=(symbal_node*)malloc(sizeof(symbal_node));
				temp->top=tail;
				temp->prev=NULL;
				temp->data=NULL;
				tail=temp;
				if(node->args)
				{
	   	 			print_ast_tree (node->args,level+1);
					struct ast_def* def_node=(struct ast_def*)(node->args);
        				struct string_list* k=(struct string_list*)def_node->vars;
					symbal_node* func_node=get_symbal_node(((struct ast_symbol_reference_node*)node->name)->name,1);
					func_node->data->last_def_arg=get_symbal_node(tail->data->name,0);	
				}
				if(node->return_type)
				{
					for(i=0;i<level+1;i++)
  						printf("  ");
					printf("return type: ");
	    				print_ast_tree (node->return_type,level+1);
				}
				if(node->funcblock)
				{
	    				print_ast_tree (node->funcblock,level+1);
                                }
                                if(get_type_from_string(get_symbal_type(((struct ast_symbol_reference_node*)node->name)->name))==node->funcblock->type)
				{
					if(node->funcblock->type==TYPE_STRING)
					{
						char* VarName=((struct ast_symbol_reference_node*)node->name)->name;		
						char* errorstring;
						errorstring="Return type of the procedure cannot be string: ";
						errorstring=strcatt(errorstring,VarName);
						errorstring=strcatt(errorstring," In Line: ");
						Error_Func_line(errorstring, node->line);
						node->type=TYPE_ERROR;	
					}
					else
                                        	node->type = node->funcblock->type;
                                }
                                else
				{
					char* VarName=((struct ast_symbol_reference_node*)node->name)->name;		
					char* errorstring;
					errorstring="Return type and procedure type must match! Procedure: ";
					errorstring=strcatt(errorstring,VarName);
					errorstring=strcatt(errorstring," In Line: ");
					Error_Func_line(errorstring, node->line);
                                        node->type = TYPE_ERROR;
                                }
				//printf("Function type is %s\n",printType(node->type));
			}
        		break;
    		case 'Z':
			{
				printf("Return ");
				struct ast_return_node * node = (struct ast_return_node *) ast_tree;
				if(node->left)
					print_ast_tree (node->left,level+1);
                                node->type = node->left->type;
			}
        		break;
    		case 'Y':
			{
				printf("Block ");
				struct ast_func_block_node * node = (struct ast_func_block_node *) ast_tree;
				if(node->commands)
				{
					print_ast_tree (node->commands,level+1);
				}
				for(i=0;i<level+1;i++)
  					printf("  ");
				//printf("(");
				printf("Return ");
				if(node->return_stm)
				{
					print_ast_tree (node->return_stm,level+1);
					node->type = node->return_stm->type;
				}
				//printf("\n");
				while(tail->prev!=NULL){
					tail=tail->prev;
				}
				tail=tail->top;
			}
        		break;
    		case 'S':  //symbol-VAR
			{
				//printf("{S}");
				char * errorstring;
				struct ast_symbol_reference_node * node = (struct ast_symbol_reference_node *) ast_tree;
				printf("%s ",node->name);
				if(strcmp(node->name, "NULL")==0)
					node->type = TYPE_NULL;
				if(node->type == TYPE_ERROR)
				{
					if(node->name[0]=='\'')
					{//char type
						node->type=TYPE_CHAR;
					}
					else if(node->name[0]=='"')
					{
						//printf("Type is String\n");
						node->type=TYPE_STRING;
					}
					else
					{
						char * type=get_symbal_type(node->name);	
						if(type!=NULL)
						{	
							node->type = get_type_from_string(type);  						
						}
                			}
				}
			}
			break;
    		case 'N':  //number
			{
				//printf("{N}");
				struct ast_number_node * node = (struct ast_number_node *) ast_tree;
				printf("%s ",node->value);
                                node->type = TYPE_INTEGER;
			}
      			break;
    		case 'R': //relational
      			{
				//printf("{R}");
        			struct ast_relational_node * node = (struct ast_relational_node *) ast_tree;
				printf("%s ",node->operator);
				Type type1=TYPE_ERROR,type2=TYPE_ERROR;
				if(node->left)
				{
          				print_ast_tree (node->left,level+1);
					type1=node->left->type;
				}
				if(node->right)
				{
	  				print_ast_tree (node->right,level+1);
					type2=node->right->type;
				}
				if(type1==type2&& type1==TYPE_INTEGER)
				{
					ast_tree->type= TYPE_BOOLEAN;
				}
				else 
				{
					char* errorstring;						
					//B=ast_tree->node_type;
					errorstring="Left and right types of operator '";
					errorstring=strcatt(errorstring,node->operator);
					errorstring=strcatt(errorstring,"' are not suitable! In Line: ");
					Error_Func_line(errorstring, node->line);
					ast_tree->type=TYPE_ERROR;
				}
      			}
      			break;
    		case 'E': //equality
      			{
				//printf("{E}");
				struct ast_equality_node * node = (struct ast_equality_node *) ast_tree;
				printf("%s ",node->operator);
                                Type type1=TYPE_ERROR,type2=TYPE_ERROR;
				if(node->left)
				{
          				print_ast_tree (node->left,level+1);
					type1=node->left->type;
				}
				if(node->right)
				{
	  				print_ast_tree (node->right,level+1);
					type2=node->right->type;
				}
				if(type1==type2&& type1!=TYPE_STRING&& type1!=TYPE_ERROR && (strcmp(node->operator,"==")||strcmp(node->operator,"!=")))
				{
					ast_tree->type= TYPE_BOOLEAN;
				}
				else if(type1==type2&& type1==TYPE_BOOLEAN && (strcmp(node->operator,"||")||strcmp(node->operator,"&&")))
				{
					ast_tree->type= TYPE_BOOLEAN;
				}
				else 
				{
					char* errorstring;						
					//B=ast_tree->node_type;
					errorstring="Left and right types of operator '";
					errorstring=strcatt(errorstring,node->operator);
					errorstring=strcatt(errorstring,"' are not suitable! In Line: ");
					Error_Func_line(errorstring, node->line);
					ast_tree->type=TYPE_ERROR;
				}
      			}
      			break;
    		case 'A': //assigment
      			{//printf("{A}");
        			struct ast_assignment_node * node = (struct ast_assignment_node *) ast_tree;
				printf("= ");
        			print_ast_tree (node->name,level+1);
        			print_ast_tree (node->value,level+1);				
				if(node->name->type != TYPE_INT_PTR && node->name->type !=TYPE_CHAR_PTR&& node->value->type == TYPE_NULL)
				{
					ast_tree->type=TYPE_ERROR;
					Error_Func_line("Type of the variable must be intptr or charptr for assignment with NULL In Line: ", node->line);
				}
                                else if(node->name->type == node->value->type)
				{
                                         ast_tree->type = node->name->type;    
                                }
                                else
				{
					if(node->name->type != TYPE_CHAR_PTR && node->name->type != TYPE_INT_PTR)
					{
                                        	ast_tree->type=TYPE_ERROR;
						char* VarName=((struct ast_symbol_reference_node*)node->name)->name;
						char*errorstring;
						if(get_symbal_node(VarName,1)==NULL) // if the variable doesnt exist
						{
							errorstring ="Undeclared Variable: ";
							errorstring = strcatt(errorstring, VarName);
							errorstring = strcatt(errorstring, " In Line: ");
							Error_Func_line(errorstring, node->line);
						}

						Error_Func_line("Left and right type of assignment are not suitable! In Line: ", node->line);
                                	}
				}
                                struct ast_node * ast_tree2 = (struct ast_node *) node->name; 
                                /*switch(ast_tree2->node_type)
				{
                                        case 'V':
                                                
                                                //struct ast_value_of_node * node2 = (struct ast_value_of_node *) ast_tree2;
                                                //printf("Asigment Type is ---->%s Left is:%s ---- Right is%s\n",printType(ast_tree->type),get_symbal_type(((struct ast_symbol_reference_node *)node2->left)->name),printType(node->value->type));
			                        //printf("%s\n",node2->name);
                                                printf("VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV\n"); 
                                                break;

                                        case 'S':
                                                printf("Asigment Type is ---->%s Left is:%s ---- Right is%s\n",printType(ast_tree->type),get_symbal_type(((struct ast_symbol_reference_node *)node->name)->name),printType(node->value->type));
                                                break;

                                        case 'H':
                                                printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n"); 
                                                break;
                                        default:
                                                printf("Something else????????????????????\n");  
                                                break;
                                }*/
      			}
      			break;
    		case 'I':
      			{
				//printf("{I}")
				struct ast_if_node * node = (struct ast_if_node *) ast_tree;
				printf("IF ");
				if(node->condition)
				{
   	  				print_ast_tree (node->condition,level+1);
                                        if(node->condition->type == TYPE_BOOLEAN)
                                        	node->type = TYPE_BOOLEAN;

                                        else 
					{
						node->type = TYPE_ERROR;
						Error_Func_line("If condition is not boolean! In Line: ", node->line);
					}
                                }
				//printf("If Type is :%s\n",printType(node->condition->type));
				if(node->if_branch)
					print_ast_tree (node->if_branch,level+1);				
				if (node->else_branch)
        			{
					for(i=0;i<level+1;i++)
  						printf("  ");
					printf("(");
					printf("ELSE ");
        				print_ast_tree (node->else_branch,level+1);
				}
      			}
      			break;
    		case 'W':
      			{
				//printf("{W}");
				struct ast_while_node * node = (struct ast_while_node *) ast_tree;
        			printf("WHILE ");
				if(node->condition)
				{
   	  				print_ast_tree (node->condition,level+1);
                                        if(node->condition->type == TYPE_BOOLEAN)
                                        	node->type = TYPE_BOOLEAN;
                                        else 
					{
						node->type = TYPE_ERROR;
						Error_Func_line("While condition is not boolean ! In Line: ", node->line);
					}

                                }
				//printf("While Type is :%s\n",printType(node->condition->type));
        			if (node->while_branch)
        			{
          				print_ast_tree (node->while_branch,level+1);
				}
      			}
      			break;
    		case 'F':
      			{
				struct ast_function_node * node = (struct ast_function_node *) ast_tree;
       				printf("%s ",node->name);
				char* VarName=node->name;
				symbal_node* varNode=get_symbal_node(VarName,1);
				if(varNode==NULL)// if the function doesnt exist
				{
					char* errorstring;
					errorstring="Undeclared Procedure: ";
					errorstring=strcatt(errorstring,VarName);
					errorstring=strcatt(errorstring," In Line: ");
					Error_Func_line(errorstring, node->line);
					node->type=TYPE_ERROR;
					break;
				}
				else
				{
					node->type=get_type_from_string(get_symbal_type(VarName));
				}
        			if (node->arguments)
        			{
          				print_ast_tree (node->arguments,level+1);
					int* arr,length=0;
					return_def_length_and_types(node->arguments,&arr,&length);
					if(varNode!=NULL && varNode->data!=NULL)
					{
						symbal_node* temp=varNode->data->last_def_arg;
						int i=length-1;
						for(i;i>=0&&temp->data!=NULL;i--)
						{
							if(strcmp(printType(arr[i]),temp->data->type_val)!=0)
							{
								Error_Func_line(strcatt(strcatt("One of the parameter in procedure call is illigle Procedure name : ",VarName)," In Line: "), node->line);
								node->type=TYPE_ERROR;
							}
							temp=temp->prev;
						}
						if(i!=-1||temp->data!=NULL)
						{
							if(i!=-1)
							{
								Error_Func_line(strcatt(strcatt("Pass more parameters then expected in procedure call: ",VarName)," In Line: "), node->line);
								node->type=TYPE_ERROR;
							}
							else
							{
								Error_Func_line(strcatt(strcatt("Pass less parameters then expected in procedure call: ",VarName)," In Line: "), node->line);
								node->type=TYPE_ERROR;
							}
						}
					}
        			}
				else if(varNode->data!=NULL &&varNode->data->last_def_arg!=NULL)
				{
					Error_Func_line(strcatt(strcatt("Pass less parameters then expected in procedure call: ",VarName)," In Line: "), node->line);
					node->type=TYPE_ERROR;
				}
      			}
      			break;
    		case'D':
      			{
				printf("Def ");
        			struct ast_def* def_node=(struct ast_def*)ast_tree;
        			struct string_list* k=(struct string_list*)def_node->vars;
        			while(k!=NULL)
				{
					insert_var(k->node,def_node->type2,0);//insert var in the symbal table
        				print_ast_tree(k->node,level+1);
					k=(struct string_list*)k->next;
				}
				print_ast_tree(def_node->type2,level+1);
				//$$ = new_ast_node('L',$2,$4);						
       			}
       			break;
    		case 'C':
      			{		
				//printf("{C}");
        			struct ast_address_of_node * node = (struct ast_address_of_node *) ast_tree;
        			if (node->name)
        			{
	  				if(node->operator == '&')
	      					printf("%c ",node->operator);
          				print_ast_tree(node->name,level+1);
        			}
                                if(node->name->type == TYPE_CHAR)
                                                node->type = TYPE_CHAR_PTR;
                                else if(node->name->type == TYPE_INTEGER)
                                                node->type = TYPE_INT_PTR;
                                else node->type = TYPE_ERROR;
      			}
      			break;
    		case 'G':
      			{
				//printf("{G}");
        			struct ast_def_index_of_node * node = (struct ast_def_index_of_node *) ast_tree;
        			if (node->name)
  			      	{
	  				printf("String in size ");
          				print_ast_tree(node->name,level+1);
        			}
                                node->type = TYPE_STRING;
      			}
      			break;
   		case 'H':
      			{
				printf("index_of_node ");
        			struct ast_var_index_of_node * node = (struct ast_var_index_of_node *) ast_tree;
        			if (node->name)
        			{
          				print_ast_tree(node->name,level+1);		
        			}
        			if (node->value)
        			{
	  				print_ast_tree(node->value,level+1);
        			}
				if(node->name->type != TYPE_STRING)
				{
					//printf("_____________________Line :     %d      ", node->line);
					
					Error_Func(strcatt("The type of the variable not string: ",(((struct ast_symbol_reference_node*)(node->name))->name)));
					node->type = TYPE_ERROR;
				}
      			}
      			break;
    		case 'O':
      			{
				//printf("{O}");
        			struct ast_index_original_node * node = (struct ast_index_original_node *) ast_tree;
        			if (node->name)
        			{
           				print_ast_tree(node->name,level+1);
                                        node->type = TYPE_INTEGER;
        			}
      			}
      			break;
    		case 'J':
      			{
				//printf("{J}");
        			struct ast_abs_node * node = (struct ast_abs_node *) ast_tree;
        			if (node->name)
        			{
	   				printf("absolute ");
	   				if(node->operator == '-')
						printf("-");
           				print_ast_tree(node->name,level+1);
        			}
                                node->type = TYPE_INTEGER;
      			}
      			break;
    		case 'V':
      			{
				//printf("{V}");
        			struct ast_value_of_node * node = (struct ast_value_of_node *) ast_tree;
        			if (node->left)
        			{
	  				printf("^");
          				print_ast_tree(node->left,level+1);
        			}
                                if(node->left->type == TYPE_CHAR_PTR)
                                                node->type = TYPE_CHAR;
                                else if(node->left->type == TYPE_INT_PTR)
                                                node->type = TYPE_INTEGER;
                                else node->type = TYPE_ERROR;
      			}
      			break;
    		default:
      			printf ("Unknown node!\n");
  	}
  	if(ast_tree->node_type!='L'&&ast_tree->node_type!='O')
	{
		if(ast_tree->node_type!='S' && ast_tree->node_type!='V' && ast_tree->node_type!='C' && ast_tree->node_type!='N')
		{	
			printf("\n");
			for(i=0;i<level+1;i++)
  				printf("  ");
  			printf(")");
		}
	}
}
// struct symbol_node* putSymbol(char*name,char* value,char* type,struct symbol_node* next,struct symbol_node* next_block,struct symbol_node* prev)
// { 
	// struct symbol_node* temp = new_symbol_node(name, value, type, next,next_block,prev);
	// tail=temp;		
	// return temp;
// }
// struct symbol_node* getSymbol(char *varname)
// {
	// struct symbol_node* current = NULL;
	// for (current = tail; current != NULL; current = current->prev)
		// if (!strcmp (current->name, varname))
			// return current;
	// return current;
// }
// int installSymbol(char* varname,char* value,char* type,struct symbol_node* next,struct symbol_node* next_block,struct symbol_node* prev)
// { 
	// if(getSymbol(varname) == NULL){
		// if(putSymbol(varname, value, type, next,next_block,prev) == NULL){          
			// printf("Error: identifier %s cannot be stored.\n", varname);
		        // return 0;       
		// }	
	        // return 1;    
	// }  
	// printf("Error: identifier %s is already defined.\n", varname);  
	// return 0;
// }
int yyerror(char *s)
{	
	if(strcmp(s,"syntax error")!=0)
	{
		fprintf (stderr, "Error : %s in line %d\n", s,yylineno);
	    	exit(0);
  	}
       // printf(" %s in line %d\n",s,yylineno);
        return 0;
}
void insert_var(struct ast_node* new_node/*Main*/,struct ast_node* new_node_type/*integer*/,int func/*1*/)
{//String incomplite
	char* errorstring;
	if(new_node==NULL)
	{
		printf("VarNode is empty cant push in the symantic table\n");
		Error_Func("VarNode is empty cant push in the symantic table  ");
		return;
	}
	//printf("******insert_var func : %d  ********\n",func);
	symbal_node* new_symbal_node=(symbal_node*)malloc(sizeof(symbal_node));
	if(!new_symbal_node)
	{
		printf("alloc fail \"insert_var\"--->new_symbal_node\n");
		Error_Func("Allocation Failed  ");
		exit(0);
	}
	if(new_node->node_type!='B'&&new_node->node_type!='Y')
	{
		struct ast_symbol_reference_node* newNode=(struct ast_symbol_reference_node*)new_node;
		//printf("WARNING*****:  %s  *****WARNING\n",newNode->name);
		if(get_symbal_node(newNode->name,0))
		{//tail->node!=NULL cheak if first function in the program
			//printf("var already exist :%s\n",newNode->name);
			errorstring="var/procedure already exist:  ";
			errorstring = strcatt(errorstring, newNode->name);
			//errorstring = strcatt(errorstring, " In Line: ");
			Error_Func(errorstring);
			return;
		}
		symbal_data* new_symbal_data=(symbal_data*)malloc(sizeof(symbal_data));
		if(!new_symbal_data)
		{
			//printf("alloc fail \"insert_var\"--->new_symbal_data\n");
			Error_Func("Allocation Failed  ");
			exit(0);
		}
		char *newstr = (char*)malloc(sizeof(newNode->name)+1);
		strcpy(newstr,newNode->name);
		new_symbal_data->name = newstr;
		if(new_node_type->node_type!='G')
		{
			struct ast_symbol_reference_node* newType=(struct ast_symbol_reference_node*)new_node_type;
			new_symbal_data->type_val = (char*)malloc(sizeof(newType->name)+1);
			//printf("WARNING******* %s  **********WARNING\n",newType->name);
			strcpy(new_symbal_data->type_val,newType->name);
		}
		else
		{
			new_symbal_data->type_val = (char*)malloc(sizeof("String")+1);
			strcpy(new_symbal_data->type_val,"string");
		}
		if(func==0)
		{
			new_symbal_data->type_node=2;
		}
		else
		{
			new_symbal_data->type_node=1;
		}
		new_symbal_data->value=NULL;//UNDEFINED IN THIS CASE
		new_symbal_node->data=new_symbal_data;
	}
	else
	{
		//printf("**************tail_top name:%s **********\n",tail->data->name);
		new_symbal_node->data=NULL;
		new_symbal_node->top=tail;
		new_symbal_node->prev=NULL;
		tail=new_symbal_node;
		return;
	}
	if(tail==NULL&&func==0)
	{
		printf("syntax error tail cann't be empty in \"insert_var\" --->tail connection\n");
		return;
	}
	else if(tail==NULL&&func==1)
	{
		tail=(symbal_node*)malloc(sizeof(symbal_node));
		tail->data=NULL;
		tail->prev=NULL;
		tail->top=NULL;
		new_symbal_node->prev=tail;
	}
	else if(tail)
	{
		new_symbal_node->top=NULL;
		new_symbal_node->prev=tail;
	}
	tail=new_symbal_node;
	if(tail->prev!=NULL&&tail->prev->data!=NULL)
	{
		//printf("**************tail_prev name:%s **********\n",tail->prev->data->name);
	}
}

symbal_node* get_symbal_node(char* name,int all_symbal_table)
{//all_symbal_table means that search in all the table and not only one scope
	if(name==NULL || strcmp(name,"")==0)
	{
		printf("can't return symbal_node in \"get_symbal_node\" name is NULL or empty\n");
		return NULL;
	}
	if(tail==NULL)
	{
		return NULL;
	}
	symbal_node* temp=tail;
	do{
		while(temp->prev!=NULL)
		{
			if(strcmp(temp->data->name,name)==0)
			{
				return temp;
			}
			temp=temp->prev;
		}
		temp=temp->top;
	}while(all_symbal_table==1&&temp);
	return NULL;
}
char* get_symbal_type(char* str)//return NULL if there is no var x   
{
	if(str==NULL)
	{
		return NULL;
	}
	symbal_node* temp= get_symbal_node(str,1);
	if(temp==NULL)
	{
		return NULL;
	}
	return temp->data->type_val;
}
/*
Type cheack_function(char* name,struct ast_node* args)
{
	Type func_type=TYPE_ERROR;
	if(args==NULL){
		func_type=
	}
}
*/
Type get_type_from_string(char* type)
{

	if(strcmp("boolean",type)==0){

		return TYPE_BOOLEAN;

	}else if(strcmp("integer",type)==0){

		return TYPE_INTEGER;

	}else if(strcmp("intptr",type)==0){

		return TYPE_INT_PTR;

	}else if(strcmp("charptr",type)==0){

		return TYPE_CHAR_PTR;

	}else if(strcmp("char",type)==0){

		return TYPE_CHAR;

	}else if(strcmp("string",type)==0){

		return TYPE_STRING;

	}else if(strcmp("String",type)==0){
		return TYPE_STRING;
	}
	return TYPE_ERROR;
}
char* printType(Type type)
{
	char* temp;
	temp="ERROR_TYPE";
	if(type==TYPE_BOOLEAN)
	{
		temp=(char*)malloc(strlen("boolean")+1);
		strcpy(temp,"boolean");

	}
	else if(type==TYPE_INTEGER)
	{
		temp=(char*)malloc(strlen("integer")+1);
		strcpy(temp,"integer");

	}
	else if(type==TYPE_INT_PTR)
	{
		temp=(char*)malloc(strlen("intptr")+1);
		strcpy(temp,"intptr");

	}
	else if(type==TYPE_CHAR_PTR)
	{
		temp=(char*)malloc(strlen("charptr")+1);
		strcpy(temp,"charptr");
	}
	else if(type==TYPE_CHAR)
	{
		temp=(char*)malloc(strlen("char")+1);
		strcpy(temp,"char");
	}
	else if(type==TYPE_STRING)
	{
		temp=(char*)malloc(strlen("string")+1);
		strcpy(temp,"string");
	}
	return temp;
}
void return_def_length_and_types(struct ast_node* node,int** arr,int* length )
{
	if(node!=NULL)
	{	
		switch(node->node_type)
		{
			case 'L':
				{
					if(node->left)
					{
						return_def_length_and_types(node->left,arr,length);
					}
					if(node->right)
					{
						return_def_length_and_types(node->right,arr,length);
					}
				}
				break;
			case 'S':
			case 'N':
				{
					(*length)++;
					int* temp=(int*)malloc(sizeof(int)*(*length)),i=0;
					for(i;i<((*length)-1);i++)
					{
						temp[i]=(*arr)[i];
					}
					temp[(*length)-1]=node->type;
					*arr=temp;
				}
				break;
			default:
			{
				(*length)++;
				int* temp=(int*)malloc(sizeof(int)*(*length)),i=0;
				for(i;i<((*length)-1);i++){
					temp[i]=(*arr)[i];
				}
				temp[(*length)-1]=node->type;
				*arr=temp;
			}
		};
	}
}
void Error_Func(char* new_error)
{	
	char* temp = (char*)malloc(strlen(Error)+strlen(new_error)+2); 
	strncpy(temp , Error, strlen(Error));
	strncpy(temp+strlen(Error), new_error, strlen(new_error));
	temp[strlen(Error)+strlen(new_error)] = '\n';
	temp[strlen(Error)+strlen(new_error)+1] = '\0';
	free(Error);
	Error = temp;
}
void Error_Func_line(char* new_error, int line)
{	
	char lineno[10];
	sprintf(lineno,"%d",line);
	char* temp = (char*)malloc(strlen(Error)+strlen(new_error)+strlen(lineno)+2); 
	strncpy(temp , Error, strlen(Error));
	strncpy(temp+strlen(Error), new_error, strlen(new_error));
	strncpy(temp+strlen(Error)+strlen(new_error), lineno, strlen(lineno));
	temp[strlen(Error)+strlen(new_error)+strlen(lineno)] = '\n';
	temp[strlen(Error)+strlen(new_error)+strlen(lineno)+1] = '\0';
	free(Error);
	Error = temp;
}
char* strcatt(char* string1,char* string2)
{
	char* temp = (char*)malloc(strlen(string1)+strlen(string2)+1); 
	strncpy(temp , string1, strlen(string1));		
	strncpy(temp+strlen(string1), string2, strlen(string2));
	temp[strlen(string1)+strlen(string2)] = '\0';		
	return temp;
}





char *mkrndstr() { 

static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char *randomString;
int length = 3;
int n;
if (length) {
    randomString = malloc(length +1); // sizeof(char) == 1, cf. C99

    if (randomString) {
        int l = (int) (sizeof(charset) -1); // (static/global, could be const or #define SZ, would be even better)
        int key;  // one-time instantiation (static/global would be even better)
        for (n = 0;n < length;n++) {        
            key = rand() % l;   // no instantiation, just assignment, no overhead from sizeof
            randomString[n] = charset[key];
        }

        randomString[length] = '\0';
    }
}

return randomString;
}


