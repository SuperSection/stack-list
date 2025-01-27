CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c11

all: main

main: main.o stack_list.o
	$(CC) $(CFLAGS) -o main main.o stack_list.o

main.o: main.c stack_list.h
	$(CC) $(CFLAGS) -c main.c

stack_list.o: stack_list.c stack_list.h
	$(CC) $(CFLAGS) -c stack_list.c

clean:
	rm -f *.o main
