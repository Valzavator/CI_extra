# Makefile for ci project

all:
	gcc -c -g *.c -std=c99 -Werror -Wall -pedantic-errors -I./include -I../include src/*.c
	gcc *.o -o ci.out -lcheck -coverage
	./ci.out
	rm *.o
