#pragma once

namespace TGC {

	class ASTStmtReader;
	class Stmt
	{
		friend class ASTStmtReader;
	public:
		Stmt() = default;
		virtual ~Stmt();

		virtual void accept(ASTStmtReader *v);
	};
}