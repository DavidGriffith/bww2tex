#
#
all: bww2tex
#
bww2tex: y.tab.o  lex.yy.o
	cc -g -o bww2tex y.tab.o lex.yy.o
#
lex.yy.o: lex.yy.c  y.tab.h
	cc -c lex.yy.c
#
lex.yy.c: expressions.l tokensDat.h tokens.h
	flex expressions.l
#
y.tab.o: y.tab.h y.tab.c tokensDat.h tokens.h
	cc -c -g y.tab.c
#
y.tab.h  y.tab.c:  grammar.y
	bison  -t -v -b y -d  grammar.y
#
