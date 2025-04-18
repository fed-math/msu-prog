output: main.o func.o test.o
	gcc main.o func.o test.o -o main

main.o: main.c
	gcc -c main.c

func.o: func.c func.h
	gcc -c func.c

test.o: test.c test.h
	gcc -c test.c
