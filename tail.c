#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ARGS 4
#define MAX_LINE_LENGTH 2047

bool parseArgs(int argc, char **argv, int *n, FILE **file);

int main(int argc, char *argv[])
{
    FILE *file = stdin;
    int n = 10;

    if (!parseArgs(argc, argv, &n, &file))
    {
        return 1;
    }

    int c;
    while ((c = fgetc(file)) != EOF)
    {
        putchar(c); // Print character to console
    }

    fclose(file);

    return 0;
}

bool parseArgs(int argc, char **argv, int *n, FILE **file)
{
    if (argc > MAX_ARGS)
    {
        fprintf(stderr, "Wrong number of arguments\n");
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        if (!strcmp(argv[i], "-n"))
        {
            char *endptr;
            *n = strtol(argv[++i], &endptr, 10);
            if (*endptr != '\0')
            {
                fprintf(stderr, "Wrong optional argument after -n\n");
                return 0;
            }
        }
        else
        {
            *file = fopen(argv[i], "r");

            if (*file == NULL)
            {
                fprintf(stderr, "Error opening file\n");
                return 0;
            }
        }
    }

    return 1;
}
