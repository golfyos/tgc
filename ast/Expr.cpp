#include "Expr.hpp"
#include "ASTStmtReader.hpp"
#include <iostream>

namespace TGC {
	Expr::~Expr()
	{
	}

	BinaryOperator::~BinaryOperator()
	{
		std::cout << "BinaryOp Destructor\n";
		delete(lhs);
		delete(rhs);
		lhs = rhs = nullptr;
	}

	BinaryOperator::BinaryOperator(Expr* l, Expr* r, Opcode o)
		:lhs(l), rhs(r), opc(o)
	{
		RType leftType = l->getType();
		RType rightType = r->getType();

		if (leftType != rightType){
			if(leftType == FLOAT || rightType == FLOAT){
				// expr = float
			}else if(leftType == INT || rightType == INT){
				// expr = int
			}
		}
	}
	void BinaryOperator::accept(ASTStmtReader* v)
	{
		v->visit(this);
	}

	IntegerLiteral::IntegerLiteral(int value): val(value) 
	{
		setType(INT);
	}
	IntegerLiteral::~IntegerLiteral()
	{
	}

	void IntegerLiteral::accept(ASTStmtReader* v)
	{
		v->visit(this);
	}

	FloatLiteral::FloatLiteral(float value): val(value)
	{
		setType(FLOAT);
	}

	FloatLiteral::~FloatLiteral()
	{
	}

	void FloatLiteral::accept(ASTStmtReader* v)
	{
		v->visit(this);
	}


}