/*
 * SerialParser.y
 * Defines a Bison parser for processing Chess Algebraic Notation files
 * Created by Andrew Davis
 * Created on 1/17/2017
 * Open source (GPL license)
 */

%language "C++" /* the parser is written in C++ */
%defines
%locations

%define parser_class_name { SerialParser }

%{
#include "SerialContext.h"
#include "SerialFunctions.h"
%}

%parse-param {SerialContext& ctxt} {const char* fileToParse}
%lex-param {SerialContext& ctxt}

%union {
	char cval;
	int ival;
	Move* mval;
};

/* declare tokens */
%token <cval> FILE PIECE
%token <ival> RANK
%token TMARK CAPT MNUM CAST CHK CHKM PROM EOL

%type <cval> file wpiece bpiece
%type <ival> rank
%type <mval> move

%destructor { delete $$; } <mval>

%{
extern int yylex(yy::SerialParser::semantic_type* yylval, yy::SerialParser::location_type* yylloc, SerialContext& ctxt);
%}

%initial-action {
	/* Filename for locations here */
	@$.begin.filename = @$.end.filename = new std::string(fileToParse);
}
%%

/* parser rules */
turn: /* nothing */
 | turn MNUM move move EOL { ctxt.addMove($3); ctxt.addMove($4); }
 | turn MNUM move CAST move EOL{ ctxt.addMove($3); ctxt.addMove($5); }
 | turn MNUM move CAST move CAST EOL { ctxt.addMove($3); ctxt.addMove($5); }
 | turn MNUM move move CAST EOL { ctxt.addMove($3); ctxt.addMove($4); }
 | turn MNUM move CAST CHK move EOL { ctxt.addMove($3); ctxt.addMove($6); }
 | turn MNUM move CAST CHK move CHK EOL { ctxt.addMove($3); ctxt.addMove($6); }
 | turn MNUM move CAST CHK move CHKM EOL { ctxt.addMove($3); ctxt.addMove($6); }
 | turn MNUM move CAST CHKM EOL { ctxt.addMove($3); }
 | turn MNUM move move CAST CHK EOL { ctxt.addMove($3); ctxt.addMove($4); }
 | turn MNUM move move CAST CHKM EOL { ctxt.addMove($3); ctxt.addMove($4); }
 | turn MNUM move CHK move EOL { ctxt.addMove($3); ctxt.addMove($5); }
 | turn MNUM move CHK move CHK EOL { ctxt.addMove($3); ctxt.addMove($5); }
 | turn MNUM move CHK move CHKM EOL { ctxt.addMove($3); ctxt.addMove($5); }
 | turn MNUM move move CHK EOL { ctxt.addMove($3); ctxt.addMove($4); }
 | turn MNUM move CHKM EOL { ctxt.addMove($3); }
 | turn MNUM move move CHKM EOL { ctxt.addMove($3); ctxt.addMove($4); }
 | turn MNUM move PROM move EOL { ctxt.addMove($3); ctxt.addMove($5); }
 | turn MNUM move PROM move PROM EOL { ctxt.addMove($3); ctxt.addMove($5); }
 | turn MNUM move move PROM EOL { ctxt.addMove($3); ctxt.addMove($4); }
 | turn MNUM move move PROM CHK EOL { ctxt.addMove($3); ctxt.addMove($4); }
 | turn MNUM move PROM move CAST EOL { ctxt.addMove($3); ctxt.addMove($5); }
 | turn MNUM move CAST move PROM EOL { ctxt.addMove($3); ctxt.addMove($5); }
 | turn MNUM move CAST CHK move PROM EOL { ctxt.addMove($3); ctxt.addMove($6); }
 | turn MNUM move CAST CHK move PROM CHK EOL { ctxt.addMove($3); ctxt.addMove($6); }
 | turn MNUM move CAST CHK move PROM CHKM EOL { ctxt.addMove($3); ctxt.addMove($6); }
 | turn MNUM move PROM CHK move EOL { ctxt.addMove($3); ctxt.addMove($6); }
 | turn MNUM move PROM CHK move PROM CHK EOL { ctxt.addMove($3); ctxt.addMove($6); }
 | turn MNUM move PROM CHK move PROM CHKM EOL { ctxt.addMove($3); ctxt.addMove($6); }
 | turn MNUM move PROM move PROM CHKM EOL { ctxt.addMove($3); ctxt.addMove($5); }
 | turn MNUM move PROM CHKM EOL { ctxt.addMove($3); }
 | turn MNUM move move PROM CHKM EOL { ctxt.addMove($3); ctxt.addMove($4); }
 | turn EOL { /* nothing */ }
 ;

move: wpiece rank file rank file { $$ = getMove($1, false, $2, $3, $4, $5); }
 | bpiece rank file rank file { $$ = getMove($1, true, $2, $3, $4, $5); }
 | wpiece rank file CAPT rank file { $$ = getMove($1, false, $2, $3, $5, $6); }
 | bpiece rank file CAPT rank file { $$ = getMove($1, true, $2, $3, $5, $6); }
 ;

wpiece: PIECE { $$ = $1; }

bpiece: TMARK PIECE { $$ = $2; }

file: FILE { $$ = $1; }

rank: RANK { $$ = $1; }

%%
namespace yy {
	void SerialParser::error(location const& loc, const std::string& s) {
		std::cerr << "Parse error at " << loc << ": " << s << std::endl;
	}
}
