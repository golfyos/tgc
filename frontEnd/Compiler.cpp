#include <cstdlib>
#include "TGC_Driver.hpp"
#include "../ast/ASTStmtReader.hpp"

int
main(const int argc, const char **argv)
{
	if (argc == 2)
	{
		TGC::TGC_Driver driver;
		driver.parse(argv[1]);
		driver.print(std::cout) << "reading file " << argv[1] << " \n";

		TGC::ASTStmtReader reader;

		driver.getAST()->accept(&reader);	
		
	}
	else
		return(EXIT_FAILURE);
	return (EXIT_SUCCESS);
}