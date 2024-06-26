/**
 * @file io.h
 * @brief Header file for reading words from file.
 * @author Marek Hric 
 */

#ifndef IO_H_
#define IO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_word(char *s, int max, FILE *f);

#endif // IO_H_
