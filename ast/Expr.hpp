#pragma once
#include "Stmt.hpp"

namespace TGC {

	class ASTStmtReader;

	/*! Test Class */
	class Expr :
		public Stmt
	{
	public:
		Expr() = default;
		virtual ~Expr();

		enum Opcode { ADD, SUB, MUL, DIV };
		enum RType { VOID, INT, FLOAT };

		void setType(RType t) { etype = t; }
		RType getType(){return etype;}
		virtual void accept(ASTStmtReader* v)=0;
	protected:
		RType etype = INT;
		int val = 0;
	};

	/*! Test Class */
	class BinaryOperator: 
		public Expr
	{
	public:
		BinaryOperator()=default;
		BinaryOperator(Expr* l, Expr* r, Opcode o);
		~BinaryOperator();

		Expr* left() { return lhs; };
		Expr* right() { return rhs; };
		Opcode getOpcode() { return opc; };

		void accept(ASTStmtReader* v);

	private:
		Expr* lhs = nullptr;
		Expr* rhs = nullptr;
		Opcode opc;

	};

	/*! Test Class */
	class IntegerLiteral:public Expr
	{
	public:
		IntegerLiteral() = default;

		IntegerLiteral(int value);

		~IntegerLiteral();

		void accept(ASTStmtReader* v);

		int getVal() {
			return val;
		};

	private:
		int val = 0;
	};

	class FloatLiteral:public Expr
	{
		public:
		FloatLiteral() = default;

		FloatLiteral(float value);

		~FloatLiteral();

		void accept(ASTStmtReader* v);

		float getVal(){
			return val;
		}

		private:
			float val = 0;
	};

	class VarDec:public Expr
	{
		public:
		VarDec() = default;
		VarDec(char* value);
		~VarDec();
		void accept(ASTStmtReader* v);

		private:
			char* val;


	};

}