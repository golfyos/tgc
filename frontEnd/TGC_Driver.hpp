#pragma once
#include <iostream>
#include <stack>

#include "tgc_scanner.hpp"
#include "def/tgc_parser.tab.hh"
#include "../ast/Expr.hpp"

namespace TGC {
	class TGC_Driver
	{
	public:
		TGC_Driver() = default;

		virtual ~TGC_Driver();

		/**
		* parse - parse from a file
		* @param filename - valid string with input file
		*/
		void parse(const char * const filename);

		void add_id( const std::string &id );

		std::ostream& print(std::ostream &stream);

		void addIntegerLiteral(int number);

		void addBinaryOperator(Expr::Opcode opcode);

		TGC::Expr* getAST();

	private:
		void parse_helper(std::istream &stream);

		std::size_t	ids = 0;

		TGC::TGC_Parser  *parser = nullptr;
		TGC::TGC_Scanner *scanner = nullptr;

		TGC::Expr* ast = nullptr;

		std::stack<TGC::Expr*> expStack;
		
		void addNode(Expr* node);
	};
}
