/*
 * SerialLexer.l
 * Lexes chess save files and sends them to the parser
 * Created by Andrew Davis
 * Created on 1/18/2017
 * Open source (GPL license)
 */

%option noyywrap
%{
#include <cstdlib>
#include <cstdio>
#include "SerialContext.h"
#include "SerialParser.tab.hh"

#define YY_DECL int yylex(yy::SerialParser::semantic_type *yylval, yy::SerialParser::location_type *yylloc, SerialContext &ctxt)

// make location include the current token
#define YY_USER_ACTION yylloc->columns (yyleng);
typedef yy::SerialParser::token token;

%}

%%

%{
	yylloc->step ();
%}

[A-Z]	{ yylval->cval = *yytext; return token::PIECE; }
[a-h]	{ yylval->cval = *yytext; return token::FILE; }
[1-8]	{ yylval->ival = atoi(yytext); return token::RANK; }
\.\.	{ return token::TMARK; }
"x"	{ return token::CAPT; }
[0-9]+\. { return token::MNUM; }
"0-0"	{ return token::CAST; }
"0-0-0" { return token::CAST; }
"+"	{ return token::CHK; }
"++"	{ return token::CHKM; }
\([A-Z]\) { return token::PROM; }
\n 	{ yylloc->lines(1); return token::EOL; }
[ \t]   { yylloc->step (); }
.	{ fprintf(stderr, "Mystery character %c\n", *yytext); }

%%
