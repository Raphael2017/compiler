/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_MOON_PARSER_BISON_H_INCLUDED
# define YY_YY_MOON_PARSER_BISON_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 29 "./moon.y" /* yacc.c:1909  */

// %code requires block

#include "syntax_tree.h"

#line 50 "moon_parser_bison.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    INTNUM = 259,
    STRING = 260,
    BREAK = 261,
    ELSE = 262,
    END_P = 263,
    ERROR = 264,
    FALSE = 265,
    IF = 266,
    INT = 267,
    RETURN = 268,
    STRING_ = 269,
    STRUCT = 270,
    TRUE = 271,
    TYPEDEF = 272,
    VOID = 273,
    WHILE = 274,
    LOW = 275,
    OR = 276,
    AND = 277,
    EQ = 278,
    NEQ = 279,
    LE = 280,
    LT = 281,
    GT = 282,
    GE = 283,
    PLUS = 284,
    MINUS = 285,
    TIMES = 286,
    DIVIDE = 287,
    UMINUS = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 68 "./moon.y" /* yacc.c:1909  */

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

#line 110 "moon_parser_bison.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int yyparse (ParseResult* result, yyscan_t scanner);

#endif /* !YY_YY_MOON_PARSER_BISON_H_INCLUDED  */
