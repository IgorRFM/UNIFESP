bison.tab.c: bison.y
	win_bison bison.y -d

main: main.c bison.tab.c
	gcc -o main main.c bison.tab.c