# Marek Hric
# FIT
# 23.4.2024
CC=gcc
CFLAGSN= -O2 -std=c11 -pedantic -Wall -Wextra
CFLAGS= -O2 -std=c11 -pedantic -Wall -Wextra -fPIC

HTAB_OBJS = htab_hash_function.o htab_init.o htab_size.o htab_bucket_count.o htab_find.o htab_lookup_add.o htab_erase.o htab_for_each.o htab_clear.o htab_free.o htab_statistics.o

.PHONY: all run doc clean zip

all: tail wordcount wordcount-dynamic

tail: tail.c
	$(CC) $(CFLAGSN) -o $@ $^

wordcount: wordcount.o libhtab.a io.o
	$(CC) $(CFLAGSN) -static -o $@ $^

wordcount-dynamic: wordcount.o libhtab.so io.o
	$(CC) $(CFLAGSN) -o $@ $^

io.o: io.c

libhtab.a: $(HTAB_OBJS)
	ar rcs $@ $^

libhtab.so: $(HTAB_OBJS)
	$(CC) $(CFLAGS) -shared -o $@ $^

htab_hash_function.o: htab_hash_function.c

htab_init.o: htab_init.c htab.h htab_private.h
htab_size.o: htab_size.c htab.h htab_private.h
htab_bucket_count.o: htab_bucket_count.c htab.h htab_private.h

htab_find.o: htab_find.c htab.h htab_private.h
htab_lookup_add.o: htab_lookup_add.c htab.h htab_private.h

htab_erase.o: htab_erase.c htab.h htab_private.h

htab_for_each.o: htab_for_each.c htab.h htab_private.h

htab_clear.o: htab_clear.c htab.h htab_private.h
htab_free.o: htab_free.c htab.h htab_private.h

htab_statistics.o: htab_statistics.c htab.h htab_private.h

run: all
	seq 1000000 2000000 | shuf | ./wordcount 
	seq 1000000 2000000 | shuf | LD_LIBRARY_PATH=. ./wordcount-dynamic 
	./tail -n 10 Makefile	

doc:
	doxygen Doxyfile

clean:
	rm -rf *.o *.a *.so *.zip wordcount wordcount-dynamic tail html/

zip:
	zip xhricm00.zip *.c *cc *.h Makefile
