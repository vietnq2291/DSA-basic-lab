main: main.o tree.o
	gcc -o main main.o tree.o
main.o: main.c tree.h
	gcc -c -g main.c
tree.o: tree.c tree.h
	gcc -c -g tree.c
