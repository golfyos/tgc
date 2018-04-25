#pragma once

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "def/tgc_parser.tab.hh"
#include "def/location.hh"

namespace TGC {
	class TGC_Scanner :public yyFlexLexer {
	public:
		TGC_Scanner(std::istream *in) : yyFlexLexer(in)
		{
		};

		virtual ~TGC_Scanner() {};

		using FlexLexer::yylex;

		virtual
		int yylex(TGC::TGC_Parser::semantic_type * const lval,
				TGC::TGC_Parser::location_type *location);

	private:
		TGC_Parser::semantic_type *yylval = nullptr;
	};
}