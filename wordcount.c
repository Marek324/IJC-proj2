#include "io.h"
#include "htab.h"

#define HTAB_SIZE 10000
#define STREAM stdin
#define MAX_WORD_SIZE 255

void print_pair(htab_pair_t *data);

int main()
{
    htab_t *htab = htab_init(HTAB_SIZE);
    FILE *input = STREAM;

    char *word = malloc(sizeof(char) * MAX_WORD_SIZE);
    if (word == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    free(word);

    while (readword(word, MAX_WORD_SIZE, input) != EOF)
    {
        htab_lookup_add(htab, word);
    }

    htab_for_each(htab, print_pair);
    
#ifdef STATISTICS
    htab_statistics(htab);
#endif

    htab_free(htab);

    return 0;
}

void print_pair(htab_pair_t *data)
{
    printf("%s\t%d\n", data->key, data->value);
}
