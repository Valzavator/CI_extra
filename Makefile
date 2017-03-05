# Makefile for ci project

all:
	gcc -c -g -std=c11 -Werror -Wall -pedantic-errors -I./include src/*.c *.c -I./ -I../include
	gcc *.o -o ci.out -lcheck
	rm *.o
	gnome-terminal --tab -e "/bin/bash -c 'valgrind --leak-check=yes ./ci.out; exec /bin/bash -i'"