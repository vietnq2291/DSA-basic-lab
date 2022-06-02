main: main.o GenSLL.o
	gcc -o main main.o GenSLL.o
main.o: main.c GenSLL.h
	gcc -c -g main.c
GenSLL.o: GenSLL.c GenSLL.h
	gcc -c -g GenSLL.c
