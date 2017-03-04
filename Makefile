# Makefile for ci project

all:
	gcc -c -g src/*.c src/tests/*.c -std=c99 -Werror -Wall -pedantic-errors -I./include -I../include -I./
	gcc *.o -o ci.out -lcheck
	rm *.o
	./ci.out