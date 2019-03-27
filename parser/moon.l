/**
 * lexer
 *
 *
 */


/***************************
 ** Section 1: Definitions
 ***************************/
%{

#include "syntax_tree.h"
#include "moon_parser_bison.h"
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <string.h>

#define YY_USER_ACTION \
		yylloc->first_line = yylloc->last_line; \
		yylloc->first_column = yylloc->last_column; \
		for(int i = 0; yytext[i] != '\0'; i++) { \
				if(yytext[i] == '\n') { \
						yylloc->last_line++; \
						yylloc->last_column = 0; \
				} \
				else { \
						yylloc->last_column++; \
				} \
		}

#define TOKEN(name) { return name; }

%}


/***************************
 ** Section 2: Rules
 ***************************/

/* Define the output files */
%option header-file="moon_parser_flex.h"
%option outfile="moon_parser_flex.cpp"

/* Make reentrant */
%option reentrant
%option bison-bridge

/* performance tweeks */
%option never-interactive
%option batch

/* other flags */
%option noyywrap
%option nounput
%option warn
%option case-insensitive
%option bison-locations
/* %option nodefault */


%x hint
%x sq
%x sb

space         [ \t\n\r\f]
non_newline   [^\n\r]
moon_comment  ("--"{non_newline}*)
whitespace    ({space}+|{moon_comment})
comment       ({moon_comment})
identifer         ([A-Za-z_][A_Za-z0-9_]*)


quote         '
sqbegin       {quote}
sqend         {quote}

sqcontent     [^']*

/***************************
 ** Section 3: Rules
 ***************************/
%%
BREAK               TOKEN(BREAK)
ELSE                TOKEN(ELSE)
FALSE               TOKEN(FALSE)
IF                  TOKEN(IF)
INT                 TOKEN(INT)
RETURN              TOKEN(RETURN)
STRING              TOKEN(STRING_)
STRUCT              TOKEN(STRUCT)
TRUE                TOKEN(TRUE)
TYPEDEF             TOKEN(TYPEDEF)
VOID                TOKEN(VOID)
WHILE               TOKEN(WHILE)

[0-9]+  {
    yylval->ival = atoi(yytext);
    return INTNUM;
}

[A-Za-z][A-Za-z0-9_]* {
    yylval->symbol = make_symbol(yytext);
	return IDENTIFIER;
}

{comment}   { /* ignore */ }
[ \t\r\n]+  { /* ignore */ }

[(),.;] { return yytext[0];}
"{"     { return yytext[0]; }
"}"     { return yytext[0]; }
"["     { return yytext[0]; }
"]"     { return yytext[0]; }
"="     { return yytext[0]; }
"+"     { return PLUS;}
"*"     { return TIMES; }
"/"     { return DIVIDE; }
"-"     {return MINUS;}
"=="    {return EQ;}
"<>"    {return NEQ;}
"<"     {return LT;}
"<="    {return LE;}
">"     {return GT;}
">="    {return GE;}
"&&"	{return AND;}
"||"	{return OR;}


{sqbegin}   {
    BEGIN(sq);
    ((ParseResult*)yyextra)->buf_ = std::stringstream{};
}

<sq>{sqcontent} {
    ((ParseResult*)yyextra)->buf_ << yytext;
}

<sq>{sqend} {
    BEGIN(INITIAL);
    yylval->sval = strdup(((ParseResult*)yyextra)->buf_.str().c_str());
    return STRING;
}

<<EOF>>    { return END_P; }

.   {
    fprintf(stderr, "[MOON-Lexer-Error] Unknown Character: %c\n", yytext[0]);
    return ERROR;
}
%%
/***************************
 ** Section 3: User code
 ***************************/
