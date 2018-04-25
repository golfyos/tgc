#include "ASTStmtReader.hpp"

namespace TGC {

	ASTStmtReader::~ASTStmtReader()
	{
	}

	void ASTStmtReader::visit(Stmt* node)
	{
		os << "Stmt\n";
	}

	void ASTStmtReader::visit(Expr* node)
	{
		os << "Expr\n";
	}

	void ASTStmtReader::visit(BinaryOperator* node)
	{
		os << "visit BinaryOperator \n";

		node->left()->accept(this);
		node->right()->accept(this);
		os << node->getOpcode() << "\n";
	}

	void ASTStmtReader::visit(IntegerLiteral* node)
	{
		os << "IntegerLiteral (" << node->getVal() << ")\n";
	}
}