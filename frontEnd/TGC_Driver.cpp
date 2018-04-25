#include <cassert>
#include <cctype>
#include <fstream>

#include "TGC_Driver.hpp"
#include "../ast/Expr.hpp"


TGC::TGC_Driver::~TGC_Driver()
{
	/* point to int type or float type */

	delete(scanner);
	scanner = nullptr;
	delete(parser);
	parser = nullptr;

	while(!expStack.empty()){
		Expr* t = expStack.top();
		delete t;
		expStack.pop();
	}
}

/**
* parse - parse from a file
* @param filename - valid string with input file
*/
void TGC::TGC_Driver::parse(const char * const filename)
{
	assert(filename != nullptr);
	std::ifstream in_file(filename);
	if (in_file.good())
	{
		parse_helper( in_file );
	}
	else
		exit(EXIT_FAILURE);
	return;
}

void TGC::TGC_Driver::add_id(const std::string &id)
{
	ids++;
}

void TGC::TGC_Driver::parse_helper(std::istream &stream)
{

	delete(scanner);
	try
	{
		scanner = new TGC::TGC_Scanner(&stream);
	}
	catch (std::bad_alloc &ba)
	{
		std::cerr << "Failed to allocate scanner: (" <<
			ba.what() << "), exiting!!\n";
		exit(EXIT_FAILURE);
	}

	delete(parser);
	try
	{
		parser = new TGC::TGC_Parser((*scanner) /* scanner */,
			(*this) /* driver */);
	}
	catch (std::bad_alloc &ba)
	{
		std::cerr << "Failed to allocate parser: (" <<
			ba.what() << "), exiting!!\n";
		exit(EXIT_FAILURE);
	}
	const int accept(0);
	if (parser->parse() != accept)
	{
		std::cerr << "Parse failed!!\n";
	}else{
		std::cout << "Accept\n";
	}
	return;
}

std::ostream&
TGC::TGC_Driver::print(std::ostream &stream)
{
	stream << "---- Tiger Compiler Frontend ----\n";
	stream << ids << " IDs found.\n";
	return(stream);
}

void TGC::TGC_Driver::addNode(Expr* node){
	expStack.push(node);
	ast = node;
}

void TGC::TGC_Driver::addIntegerLiteral(int number){
	IntegerLiteral* node = new IntegerLiteral(number);
	addNode(node);
}

void TGC::TGC_Driver::addBinaryOperator(Expr::Opcode opcode){
	Expr* r = expStack.top();
	expStack.pop();
	Expr* l = expStack.top();
	expStack.pop();
	

	BinaryOperator* node = new BinaryOperator(l,r,opcode);
	addNode(node);
}

TGC::Expr* TGC::TGC_Driver::getAST(){
	return ast;
}

