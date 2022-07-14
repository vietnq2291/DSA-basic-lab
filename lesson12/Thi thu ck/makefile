main: main.o ./lib/tree.o
	gcc -o main main.o ./lib/tree.o
main.o: main.c ./lib/tree.h
	gcc -c -g main.c
tree.o: ./lib/tree.c ./lib/tree.h
	gcc -c -g ./lib/tree.c
