%{
	#include <string>
	/* Implementation of yyFlexScanner */ 
	#include "../tgc_scanner.hpp"
	#undef  YY_DECL
	#define YY_DECL int TGC::TGC_Scanner::yylex( TGC::TGC_Parser::semantic_type * const lval, TGC::TGC_Parser::location_type *loc )

	/* typedef to make the returns for the tokens shorter */
	using token = TGC::TGC_Parser::token;

	/* define yyterminate as this instead of NULL */
	#define yyterminate() return( token::END )

	/* msvc2010 requires that we exclude this header file. */
	#define YY_NO_UNISTD_H

	/* update location on matching */
	#define YY_USER_ACTION loc->step(); loc->columns(yyleng);
%}

%option debug
%option yyclass="TGC::TGC_Scanner"
%option noyywrap
%option c++

%%
%{
	/** Code executed at the beginning of yylex **/
	yylval = lval;
%}

"("			{return( token::ORB);}

")"			{return( token::CRB);}

","			{return( token::COMMA);}

"+"			{return( token::ADD);}
"-"			{return (token::SUB);}
"*"			{return (token::MULTI);}
"/"			{return (token::DIVIDE);}

"int" 		{return (token::INT);}
"float" 	{return(token::FLOAT);}

[0-9]+		{
				yylval->build< std::string >( yytext );
				return ( token::NUMBER);
			}

\n			{
				// Update line number
				loc->lines();
				return( token::NEWLINE );
			}

[a-zA-Z]+   {
               /**
                * Section 10.1.5.1 of the 3.0.2 Bison Manual says the 
                * following should work:
                * yylval.build( yytext );
                * but it doesn't.
                * ref: http://goo.gl/KLn0w2
                */
               yylval->build< std::string >( yytext );
               return( token::ID );
            }
%%
