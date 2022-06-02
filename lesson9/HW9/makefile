main: main.o GenDLL.o
	gcc -o main main.o GenDLL.o
main.o: main.c GenDLL.h
	gcc -c -g main.c
GenDLL.o: GenDLL.c GenDLL.h
	gcc -c -g GenDLL.c
