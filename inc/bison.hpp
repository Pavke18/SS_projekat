/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_INC_BISON_HPP_INCLUDED
# define YY_YY_INC_BISON_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    GLOBAL = 258,
    EXTERN = 259,
    SECTION = 260,
    WORD = 261,
    SKIP = 262,
    EQU = 263,
    END = 264,
    SYMBOL = 265,
    NUMBER = 266,
    REG = 267,
    PLUS = 268,
    MINUS = 269,
    COLON = 270,
    DOT = 271,
    COMMA = 272,
    STAR = 273,
    COMMENT = 274,
    DOLLAR = 275,
    PERCENT = 276,
    BRACKET_L = 277,
    BRACKET_R = 278,
    SQBRACKET_L = 279,
    SQBRACKET_R = 280,
    MULTIP = 281,
    NOVI_RED = 282,
    QUIT = 283,
    JMP = 284,
    JEQ = 285,
    JNE = 286,
    JGT = 287,
    CALL = 288,
    PUSH = 289,
    POP = 290,
    INT = 291,
    NOT = 292,
    HALT = 293,
    RET = 294,
    IRET = 295,
    XCHG = 296,
    ADD = 297,
    SUB = 298,
    MUL = 299,
    DIV = 300,
    CMP = 301,
    AND = 302,
    OR = 303,
    XOR = 304,
    TEST = 305,
    SHL = 306,
    SHR = 307,
    LDR = 308,
    STR = 309,
    DIVIDE = 310
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "src/parser.y"

	int ival;
	char *sval;

#line 118 "inc/bison.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_INC_BISON_HPP_INCLUDED  */
