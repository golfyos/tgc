#include "Stmt.hpp"
#include "ASTStmtReader.hpp"


namespace TGC {

	Stmt::~Stmt()
	{
	}

	void Stmt::accept(ASTStmtReader *v)
	{
		v->visit(this);
	}
}