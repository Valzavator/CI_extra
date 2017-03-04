# Makefile for ci project

all:
	gcc -c -g *.c -std=c11 -Werror -Wall -pedantic-errors -I./include -I../include src/*.c
	gcc *.o -o ci.out -lcheck
	rm *.o
	gnome-terminal --tab -e "/bin/bash -c 'valgrind --leak-check=yes ./ci.out; exec /bin/bash -i'"
