# Linux tail command / Hashtable wordcount both in C

Project was assigned in my C programming langauge course at FIT BUT. First part of the assignment was to make a non-modular C replica of shell `tail` command. Second part was to implement own **hash table with separate chaining** and use it to count instances of words on stdin. Also added **Doxygen** documentation because I wanted to try it out.

## Linux shell command tail made in C

Prints the last _N_ (default: 10) lines from optional argument _FILE_ (default:STDIN).

### Implementation details

My `tail` uses circular buffer to store last _N_ lines. Overwrites oldest item in buffer when more than _N_ lines are present.

### Instalation

If you want to install only _tail_ part of this project download:

-   tail.c
-   Makefile

Being in the same directory as `tail.c` and `Makefile` run:

```bash
make tail
```

Now you can remove `tail.c` and `Makefile` as they are not needed anymore.

### Usage

Linux: `./tail [FILE] [-n N]` where _N_ stands for number of last lines to print.

## Wordcount using hashtable

Prints how many times words appear in the text

### Implementation details

Functions are in separate files and are put together into one library during compilation. You can use statically or dynamically linked library.

### Instalation

For this program you'll need:

-   htab_bucked_count.c
-   htab_clear.c
-   htab_erase.c
-   htab_find.c
-   htab_for_each.c
-   htab_free.c
-   htab_hash_function.c
-   htab_init.c
-   htab_lookup_add.c
-   htab_private.h
-   htab_size.c
-   htab_statistics.c
-   htab.h
-   io.c
-   io.h
-   wordcount.c

For statically linked library you'll want to run:

```bash
make wordcount
```

If you want to compile without library:

```bash
make wordcount-dynamic
```

### Usage

Simply run `./wordcount` and paste/redirect text. The program will output words with their count **not** in order.
