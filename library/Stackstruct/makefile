main: main.o stackstruct.o
	gcc -o main main.o stackstruct.o
main.o: main.c stackstruct.h
	gcc -c -g main.c
stackstruct.o: stackstruct.c stackstruct.h
	gcc -c -g stackstruct.c
