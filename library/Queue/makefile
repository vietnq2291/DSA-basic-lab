main: main.o queueSLL.o
	gcc -o main main.o queueSLL.o
main.o: main.c queueSLL.h
	gcc -c -g main.c
queueSLL.o: queueSLL.c queueSLL.h
	gcc -c -g queueSLL.c
