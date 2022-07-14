main: main.o stackarr.o
	gcc -o main main.o stackarr.o
main.o: main.c stackarr.h
	gcc -c -g main.c
stackarr.o: stackarr.c stackarr.h
	gcc -c -g stackarr.c
