/**
 * @file wordcount.c
 * @brief Program that reads words from input and counts their occurences using hash table.
 * Second task of the 2nd assignment in my "The C Programming Language" course.
 * @author Marek Hric
 * @bug Memory not properly freed. 
*/

#include "io.h"
#include "htab.h"

#define HTAB_SIZE 10289
#define STREAM stdin
#define MAX_WORD_SIZE 256

void print_pair(htab_pair_t *data);

/**
 * @brief Main function of the program.
 * 
 * @return int exit code 
 */

int main()
{
    htab_t *htab = htab_init(HTAB_SIZE);
    FILE *input = STREAM;

    char *word = malloc((sizeof(char) + 2) * MAX_WORD_SIZE);
    if (word == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        htab_free(htab);
        free(word);
        return 1;
    }

    int wordLenError = 1;
    int len = 0;
    while ((len = read_word(word, MAX_WORD_SIZE, input)) != EOF)
    {
        if (len == MAX_WORD_SIZE - 1 && wordLenError > 0)
        {
            fprintf(stderr, "Error: Word too long, truncated\n");
            wordLenError--;
        }
        htab_pair_t *pairPtr = htab_lookup_add(htab, word);
        if (pairPtr == NULL)
        {
            fprintf(stderr, "Memory allocation failed.\n");
            htab_free(htab);
            free(word);
            return 1;
        }
    }
    free(word);

    htab_for_each(htab, print_pair);

#ifdef STATISTICS
    htab_statistics(htab);
#endif

    htab_free(htab);

    return 0;
}

/**
 * @brief Function that prints key and value of a pair.
 * @fn void print_pair(htab_pair_t *data)
 * @param data Pointer to the pair.
 */

void print_pair(htab_pair_t *data)
{
    printf("%s\t%d\n", data->key, data->value);
}