CC = gcc
LEX = flex --nounistd
YACC = bison
FLAGS = -O2

# Define where you want bww2tex installed.  Usually this is /usr/local.
PREFIX = /usr/local
MAN_PREFIX = $(PREFIX)


########################################

VERSION = 2.01
BINNAME = bww2tex
DISTNAME = $(BINNAME)-$(VERSION)

OBJECTS = lex.yy.o y.tab.o

$(BINNAME): $(OBJECTS) 
	$(CC) $(FLAGS) -o $(BINNAME) $(OBJECTS)

y.tab.c:
	$(YACC) -t -v -d -b y grammar.y

lex.yy.c:
	$(LEX) expressions.l

y.tab.o: y.tab.c
	$(CC) -c -g y.tab.c

lex.yy.o: lex.yy.c y.tab.c
	$(CC) -c -g lex.yy.c

clean:
	rm -f *~ *.o y.* lex*

distclean: clean
	rm -rf $(BINNAME) $(DISTNAME) $(DISTNAME).tar.gz

dist:	distclean
	mkdir $(DISTNAME)
	@for file in `ls`; do \
		if test $$file != $(DISTNAME); then \
			cp -Rp $$file $(DISTNAME)/$$FILE; \
		fi; \
	done
	find $(DISTNAME) -type l -exec rm -f {} \;
	tar chof $(DISTNAME).tar $(DISTNAME) --exclude=.svn
	gzip -f --best $(DISTNAME).tar
	rm -rf $(DISTNAME)
	@echo
	@echo "$(DISTNAME).tar.gz created"
	@echo

install: $(BINNAME)
	strip $(BINNAME)
	install -d $(PREFIX)/bin
	install -d $(MAN_PREFIX)/man/man1
	install -c -m 755 $(BINNAME) $(PREFIX)/bin
	install -c -m 644 $(BINNAME).1 $(MAN_PREFIX)/man/man1

uninstall:
	rm -f $(PREFIX)/bin/$(BINNAME)
	rm -f $(MAN_PREFIX)/man/man1/$(BINNAME).1

deinstall:	uninstall

remove:		uninstall
