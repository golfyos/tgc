
.PHONY: all
# all: parser lexer

# parser: tgc_parser.yy
# 	bison -d -v tgc_parser.yy

# lexer: tgc_lexer.l
# 	flex --outfile=tgc_lexer.yy.cc  $<


CXX   ?= g+
CDEBUG = -g -Wall
CXXDEBUG = -g -Wall
CXXSTD = -std=c++14
EXE = tigerc
CXXFLAGS = -Wno-deprecated-register -O0  $(CXXDEBUG) $(CXXSTD)

#CPPOBJ = main mc_driver
CPPOBJ = ../../ast/Stmt ../../ast/Expr ../../ast/ASTStmtReader ../Compiler ../TGC_Driver 
SOBJ =  parser lexer

FILES = $(addsuffix .cpp, $(CPPOBJ))
OBJS  = $(addsuffix .o, $(CPPOBJ))

wc: $(FILES)
	$(MAKE) $(SOBJ)
	$(MAKE) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(EXE) $(OBJS) parser.o lexer.o $(LIBS)

parser: tgc_parser.yy
	bison -d -v tgc_parser.yy
	$(CXX) $(CXXFLAGS) -c -o parser.o tgc_parser.tab.cc

lexer: tgc_lexer.l
	flex --outfile=tgc_lexer.yy.cc $<
	$(CXX)  $(CXXFLAGS) -c tgc_lexer.yy.cc -o lexer.o


CLEANLIST =  $(addsuffix .o, $(OBJ)) $(OBJS) \
				 tgc_parser.tab.cc tgc_parser.tab.hh \
				 location.hh position.hh \
			    stack.hh tgc_parser.output parser.o \
				 lexer.o tgc_lexer.yy.cc $(EXE)\

clean:
	rm -rf $(CLEANLIST)

# Goal : S NEWLINE|END;
# S : ORB L CRB
# 	  |	ID				{driver.add_id( $1 );}
# 	  ;	

# 	L : S
# 	  | L COMMA S
# 	  ;	