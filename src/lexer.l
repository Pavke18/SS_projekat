%option noyywrap

%{
#include <iostream>
#include <string>
#include <cstdio>
#include "bison.hpp"

using namespace std;

extern int yylex();

int red=1;
%}


digit [0-9]+
symb [a-zA-Z_][a-zA-Z_0-9]+
hex 0[xX][0-9a-fA-F]{1,4}
comment #.*\n

%%
[ \t\r]
\n {//cout<<"Novi red"<<endl;
++red; return NOVI_RED;}
"quit"    {//cout<<"quit"<<endl;
 return QUIT;}
"exit"    {//cout<<"exit"<<endl;
 return QUIT;}
{comment} {//cout<<"comment"<<endl;
 ++red; return COMMENT; } //ignorisi komentare
"+" {return PLUS;} 
"-" {return MINUS;} 
"/" {return DIVIDE;} 
"*" {return MULTIP;}
":" {return COLON;} 
"." {return DOT;}
"," {return COMMA;} 
"(" {return BRACKET_L;} 
")" {return BRACKET_R;} 
"[" {return SQBRACKET_L;} 
"]" {return SQBRACKET_R;} 
"$" {return DOLLAR;} 
"%" {return PERCENT;}
"global"  {return GLOBAL;}
"extern"  {return EXTERN;}
"section" {return SECTION;}
"word"    {return WORD; }
"skip"    {return SKIP;}
"equ"     {return EQU;}
"end"     {return END;}
"halt"    {return HALT;}
"int"     {return INT;}
"iret"    {return IRET;}
"call"    {return CALL;}
"ret"     {return RET;}
"jmp"     {return JMP;}
"jeq"     {return JEQ;}
"jne"     {return JNE;}
"jgt"     {return JGT;}
"push"    {return PUSH;}
"pop"     {return POP;}
"xchg"    {return XCHG;}
"add"     {return ADD;}
"sub"     {return SUB;}
"mul"     {return MUL;}
"div"     {return DIV;}
"cmp"     {return CMP;}
"not"     {return NOT;}
"and"     {return AND;}
"or"      {return OR;}
"xor"     {return XOR;}
"test"    {return TEST;}
"shl"     {return SHL;}
"shr"     {return SHR;}
"ldr"     {return LDR;}
"str"     {return STR;}
"sp"      {yylval.ival = 6; return REG;}
"pc"      {yylval.ival = 7; return REG;}
"psw"     {yylval.ival = 8; return REG;}
(r[0-7])  {yylval.ival = atoi(yytext+1); return REG;}
{symb}    {yylval.sval = strdup(yytext); return SYMBOL;}
{digit}   { yylval.ival = atoi(yytext); return NUMBER; }
{hex}     { yylval.ival = stoi(yytext, nullptr, 16); return NUMBER;}

%%

