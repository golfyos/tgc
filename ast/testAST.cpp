#include "Stmt.hpp"
#include "ASTStmtReader.hpp"

using namespace TGC;

int main()
{
	IntegerLiteral *l1, *r1;

	l1 = new IntegerLiteral(5);
	r1 = new IntegerLiteral(3);

	BinaryOperator *e1= new BinaryOperator((Expr*) l1, (Expr*) r1, Expr::MUL);

	IntegerLiteral *r2 = new IntegerLiteral(7);

	BinaryOperator *e2 = new BinaryOperator((Expr*)e1, (Expr*)r2, Expr::ADD);

	ASTStmtReader visitor;

	visitor.visitBinaryOperator(e2);

	delete e2;
	return 0;
}