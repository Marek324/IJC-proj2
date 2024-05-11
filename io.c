/**
 * @file io.c
 * @brief Functions for reading words from a file.
 * Reads one word from a file and stores it in a string.
 * @author Marek Hric
 * @bug No known bugs.
 */

#include "io.h"
#include <ctype.h>

/**
 * @brief Reads one word from a file and stores it in a string.
 * @fn int read_word(char *s, int max, FILE *f)
 *
 * @param s pointer to the string where the word will be stored
 * @param max maximum length of the string
 * @param f pointer to the file
 * @return int length of the string or EOF if there are no more words
 */

int read_word(char *s, int max, FILE *f)
{
    int c;
    int length = 0;

    // Skip leading whitespaces
    while ((c = fgetc(f)) != EOF && isspace(c))
        ;

    // Read characters until next whitespace or EOF
    while (c != EOF && !isspace(c) && length < max - 1)
    {
        *s++ = c;
        length++;
        c = fgetc(f);
    }

    // Null-terminate the string
    *s = '\0';

    // Return length of the string or EOF if there are no more words
    return (length > 0) ? length : EOF;
}
