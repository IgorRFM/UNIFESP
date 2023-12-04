CC = gcc
BISON = win_bison
LEX = flex

BIN = compiler

OBJS = bison.tab.o main.o util.o

$(BIN): $(OBJS)
	$(CC) $(OBJS) -o $(BIN)

main.o: main.c globals.h util.h scan.h
	$(CC) -c main.c

util.o: util.c util.h globals.h
	$(CC) -c util.c

bison.tab.o: bison.y globals.h
	$(BISON) -d bison.y
	$(CC) -c bison.tab.c

clean: