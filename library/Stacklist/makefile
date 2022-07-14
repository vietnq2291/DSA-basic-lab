main: main.o stacklist.o
	gcc -o main main.o stacklist.o
main.o: main.c stacklist.h
	gcc -c -g main.c
stacklist.o: stacklist.c stacklist.h
	gcc -c -g stacklist.c
