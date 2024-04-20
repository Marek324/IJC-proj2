CC = gcc 
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra 

.PHONY: clean zip

tail: tail.c
	$(CC) $(CFLAGS) -o tail tail.c
