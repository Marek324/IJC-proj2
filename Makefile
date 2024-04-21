CC = gcc 
CFLAGS = -g -std=c11 -pedantic -Wall -Wextra 

.PHONY: clean zip memtest 

tail: tail.c
	$(CC) $(CFLAGS) -o tail tail.c

clean: 
	rm -f *o tail

test: 
	make -f test.mk
