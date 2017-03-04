# Makefile for ci project

all:
	gcc -c -g *.c src/*.c -std=c99 -Werror -Wall -pedantic-errors -I./include -I../include 
	gcc *.o -o ci.out -lcheck -coverage
	./ci.out
	rm *.o