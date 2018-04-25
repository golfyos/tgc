#pragma once
#include <iostream>
#include "Expr.hpp"

namespace TGC {
	class ASTStmtReader
	{
	public:
		ASTStmtReader() :os(std::cout) {};
		virtual ~ASTStmtReader();

		void visit(Stmt* node);
		void visit(Expr* node);
		void visit(BinaryOperator* node);
		void visit(IntegerLiteral* node);
	private:
		std::ostream &os; 
	};
}
