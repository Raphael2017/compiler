%{
/**
 * This Grammar is designed for moon script.
 */
/*********************************
 ** Section 1: C Declarations
 *********************************/

#include "moon_parser_bison.h"
#include "moon_parser_flex.h"

/*
 * We provide parse error includes error message, first line, first column of error lex for debug
 */
int yyerror(YYLTYPE* llocp, ParseResult* result, yyscan_t scanner, const char *msg) {
    //result->accept = false;
    result->errFirstLine = llocp->first_line;
    result->errFirstColumn = llocp->first_column;
    result->errDetail = msg;
	return 0;
}


%}
/*********************************
 ** Section 2: Bison Parser Declarations
 *********************************/

%code requires {
// %code requires block

#include "syntax_tree.h"
}

// Auto update column and line number

// Define the names of the created files (defined in Makefile)
%output  "moon_parser_bison.cpp"
%defines "moon_parser_bison.h"

// Tell bison to create a reentrant parser
%define api.pure full

%define parse.error verbose
%locations

%initial-action {
	// Initialize
	@$.first_column = 0;
	@$.last_column = 0;
	@$.first_line = 0;
	@$.last_line = 0;
};


// Define additional parameters for yylex (http://www.gnu.org/software/bison/manual/html_node/Pure-Calling.html)
%lex-param   { yyscan_t scanner }

// Define additional parameters for yyparse
%parse-param { ParseResult* result }
%parse-param { yyscan_t scanner }


/*********************************
 ** Define all data-types (http://www.gnu.org/software/bison/manual/html_node/Union-Decl.html)
 *********************************/
%union
{
    struct SyntaxMoonStmtsList *moon_stmts_list;
    struct SyntaxMoonStmt *moon_stmt;
    struct SyntaxTypeFieldsList *type_fields_list;
    struct SyntaxLeftV *left_val;
    struct SyntaxTypeField *type_field;
    SyntaxType *type;
    SyntaxExp *expr;
    SyntaxExpsList *exps_list;
    Symbol *symbol;
    int ival;
    char *sval;
}


/*********************************
 ** Destructor symbols
 *********************************/


/*********************************
 ** Token Definition
 *********************************/
%token <symbol> IDENTIFIER
%token <ival> INTNUM
%token <sval> STRING

%token BREAK
%token ELSE END_P ERROR
%token FALSE
%token IF INT
%token NIL
%token RETURN
%token STRING_ STRUCT
%token TRUE TYPEDEF
%token VOID
%token WHILE


%left '['
%right '='
%left OR
%left AND
%nonassoc EQ NEQ LE LT GT GE
%left PLUS MINUS
%left TIMES DIVIDE
%left UMINUS

%type <moon_stmts_list> moon
%type <moon_stmts_list> moon_body1
%type <moon_stmts_list> moon_stmts1
%type <moon_stmt> moon_stmt1
%type <moon_stmts_list> moon_body
%type <moon_stmts_list> moon_stmts
%type <moon_stmt> moon_stmt
%type <moon_stmt> declare_variable_stmt
%type <type_fields_list> struct_elem_list
%type <moon_stmt> declare_type_stmt
%type <type_fields_list> type_fields
%type <moon_stmt> declare_function_stmt
%type <moon_stmt> if_stmt
%type <moon_stmt> while_stmt
%type <moon_stmt> return_stmt
%type <moon_stmt> break_stmt
%type <left_val> left_value
%type <type_field> type_field
%type <type> type
%type <expr> expression
%type <exps_list> expression_list

%start moon
%%
/*********************************
 ** Section 3: Grammar Definition
 *********************************/

moon:
    moon_body1 END_P { $$ = $1; accept($$, result); YYACCEPT; }
;

moon_body1:
  moon_stmts1
;

moon_stmts1:
    moon_stmt1			{ $$ = make_moon_stmts($1, nullptr); }
  | moon_stmt1 moon_stmts1	{ $$ = make_moon_stmts($1, $2); }
;

moon_stmt1:
    declare_variable_stmt ';'
  | declare_type_stmt ';'
  | declare_function_stmt
;

moon_body:
    /* EMPTY */	{ $$ = nullptr; }
  | moon_stmts
;

moon_stmts:
    moon_stmt			{ $$ = make_moon_stmts($1, nullptr); }
  | moon_stmt moon_stmts	{ $$ = make_moon_stmts($1, $2); }
;

moon_stmt:
    declare_variable_stmt ';'
  | if_stmt
  | while_stmt
  | expression ';'	{ $$ = make_exp_stmt($1); }
  | return_stmt ';'
  | break_stmt ';'
;

declare_variable_stmt:
    type IDENTIFIER				{ $$ = make_decl_var_stmt($1, $2, nullptr); }
  | type IDENTIFIER '=' expression		{ $$ = make_decl_var_stmt($1, $2, $4); }
;

struct_elem_list:
    type IDENTIFIER ';'				{ auto t = make_type_field($1, $2); $$ = make_type_fields(t, nullptr);  }
  | type IDENTIFIER ';' struct_elem_list	{ auto t = make_type_field($1, $2); $$ = make_type_fields(t, $4); }
;

declare_type_stmt:
    TYPEDEF type IDENTIFIER			{ $$ = make_decl_type_typedef_stmt($2, $3); }
  | STRUCT IDENTIFIER '{' struct_elem_list '}'	{ $$ = make_decl_type_struct_stmt($4, $2); }
;

type_fields:
    type_field			{ $$ = make_type_fields($1, nullptr); }
  | type_field ',' type_fields	{ $$ = make_type_fields($1, $3); }
;

declare_function_stmt:
    type IDENTIFIER '(' type_fields ')' '{' moon_body '}'	{ $$ = make_decl_func_stmt($1, $2, $4, $7);  }
  | type IDENTIFIER '('             ')' '{' moon_body '}'	{ $$ = make_decl_func_stmt($1, $2, nullptr, $6);  }
;

if_stmt:
    IF '(' expression ')' '{' moon_body '}'				{ $$ = make_if_stmt($3, $6, nullptr); }
  | IF '(' expression ')' '{' moon_body '}' ELSE '{' moon_body '}'	{ $$ = make_if_stmt($3, $6, $10); }
;

while_stmt:
    WHILE '(' expression ')' '{' moon_body '}'	{ $$ = make_while_stmt($3, $6); }
;

return_stmt:
    RETURN				{ $$ = make_return_stmt(nullptr); }
  | RETURN expression			{ $$ = make_return_stmt($2); }
;

break_stmt:
    BREAK				{ $$ = make_break_stmt(); }

left_value:
    IDENTIFIER	%prec MINUS		{ $$ = make_simple_left_value($1); }
  | left_value '.' IDENTIFIER		{ $$ = make_struct_field_left_value($1, $3); }
  | left_value '[' expression ']'	{ $$ = make_array_index_left_value($1, $3); }
;

type_field:
    type IDENTIFIER			{ $$ = make_type_field($1, $2); }
;

type:
    IDENTIFIER				{ $$ = make_named_type($1); }
  | INT					{ $$ = make_int_type(); }
  | STRING_				{ $$ = make_string_type(); }
  | left_value '[' ']'
{
    /* ???? */
    /* because it will be reduced by left_value : IDENTIFIER */
    if ($1->kind_ != SyntaxLeftV::Simple) {
        yyerror(&@1, result, scanner, "type use error");
        YYABORT;
    }
    $$ = make_named_arr_type($1->u.name_, 0);
}
  | INT '[' ']'				{ $$ = make_int_arr_type(0); }
;

expression:
    INTNUM				{ $$ = make_expr_int_const($1); }
  | NIL					{ $$ = make_expr_nil_const(); }
  | TRUE				{ $$ = make_expr_bool_const(true); }
  | FALSE				{ $$ = make_expr_bool_const(false); }
  | STRING				{ $$ = make_expr_str_const($1); }
  | left_value				{ $$ = make_expr_left_value($1); }
  | IDENTIFIER '(' expression_list ')'	{ $$ = make_expr_func_call($1, $3); }
  | IDENTIFIER '(' ')'			{ $$ = make_expr_func_call($1, nullptr); }
  | left_value '=' expression		{ $$ = make_expr_assign($1, $3); }
  | MINUS expression			{ $$ = make_expr_op(NEGATIVE_OP, $2, nullptr); }
  | expression OR expression		{ $$ = make_expr_op(OR_OP, $1, $3); }
  | expression AND expression		{ $$ = make_expr_op(AND_OP, $1, $3); }
  | expression LT expression		{ $$ = make_expr_op(LT_OP, $1, $3); }
  | expression GT expression		{ $$ = make_expr_op(GT_OP, $1, $3); }
  | expression LE expression		{ $$ = make_expr_op(LE_OP, $1, $3); }
  | expression GE expression		{ $$ = make_expr_op(GE_OP, $1, $3); }
  | expression PLUS expression		{ $$ = make_expr_op(PLUS_OP, $1, $3); }
  | expression MINUS expression		{ $$ = make_expr_op(MINUS_OP, $1, $3); }
  | expression TIMES expression		{ $$ = make_expr_op(TIMES_OP, $1, $3); }
  | expression DIVIDE expression	{ $$ = make_expr_op(DIVIDE_OP, $1, $3); }
  | expression EQ expression		{ $$ = make_expr_op(EQ_OP, $1, $3); }
  | expression NEQ expression		{ $$ = make_expr_op(NEQ_OP, $1, $3); }
  | type '{' expression_list '}'	{ $$ = make_expr_struct_array_init($3, $1); }
  | '(' expression ')'			{ $$ = $2; }
;

expression_list:
    expression				{ $$ = make_expr_list($1, nullptr); }
  | expression ',' expression_list	{ $$ = make_expr_list($1, $3); }

%%



    