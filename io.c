#include "io.h"

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
