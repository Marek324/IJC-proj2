/**
 * @file tail.c
 * @brief Program that prints the last n lines of a file or stdin.
 * First task of the project.
 * @author Marek Hric
 * @bug No known bugs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ARGS 4
#define MAX_LINE_LENGTH 2047

/**
 * @struct CircularBufferT
 * @brief Structure that represents a circular buffer.
 */

typedef struct
{
    int readIx;
    int writeIx;
    int size;
    char **lines;
} CircularBufferT;

bool parseArgs(int argc, char **argv, int *n, FILE **file);

CircularBufferT *cbuf_create(int length);
int cbuf_put(CircularBufferT *cb, const char *line);
char *cbuf_get(CircularBufferT *cb);
void cbuf_free(CircularBufferT *cb);

/**
 * @brief Main function of the program.
 *
 * @param argc number of arguments
 * @param argv array of arguments
 * @return int exit code
 */

int main(int argc, char *argv[])
{
    FILE *file = stdin;
    int n = 10;

    if (!parseArgs(argc, argv, &n, &file))
    {
        return 1;
    }

    if (n == 0)
        return 0; // Arguments are checked and we want to print 0 lines so there's no point in continuing the program

    CircularBufferT *cbuf = cbuf_create(n);
    if (cbuf == NULL)
    {
        fprintf(stderr, "Error allocating memory for buffer\n");
        return 1;
    }

    bool lineLenErr = 1;

    char line[MAX_LINE_LENGTH + 2];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        if (strlen(line) > MAX_LINE_LENGTH)
        {
            if (lineLenErr)
            {
                fprintf(stderr, "Error: The line is too long and has been truncated\n");
                lineLenErr = !lineLenErr;
            }

            line[MAX_LINE_LENGTH] = '\n';
            line[MAX_LINE_LENGTH + 1] = '\0';
        }

        cbuf_put(cbuf, line);
    }

    char *outLine;
    while ((outLine = cbuf_get(cbuf)) != NULL)
    {
        printf("%s", outLine);
        free(outLine);
    }

    cbuf_free(cbuf);

    fclose(file);

    return 0;
}

/**
 * @brief Function that creates a circular buffer.
 * @fn CircularBufferT *cbuf_create(int size)
 *
 * @param size size of the buffer
 * @return pointer to the buffer
 */

CircularBufferT *cbuf_create(int size)
{
    CircularBufferT *cb = malloc(sizeof(CircularBufferT));
    if (cb == NULL)
        return NULL;

    cb->readIx = 0;
    cb->writeIx = 0;
    cb->size = size + 1;

    cb->lines = (char **)malloc(sizeof(char *) * cb->size);
    if (cb->lines == NULL)
    {
        free(cb);
        return NULL;
    }
    return cb;
}

char *strAlloc(const char *str);

/**
 * @brief Function that puts a line into the buffer.
 * @fn int cbuf_put(CircularBufferT *cb, const char *line)
 *
 * @param cb pointer to the buffer
 * @param line line to be put into the buffer
 * @return 1 if successful, 0 if not
 */

int cbuf_put(CircularBufferT *cb, const char *line)
{
    if (((cb->writeIx + 1) % cb->size) == cb->readIx)
    {                                // Full buffer
        free(cb->lines[cb->readIx]); // Free oldest element in buffer
        cb->readIx++;                // Change to new oldest element in buffer
        cb->readIx = (cb->readIx % cb->size);
    }
    char *newLine = strAlloc(line);
    if (newLine == NULL)
        return 0;

    cb->lines[cb->writeIx] = newLine;

    cb->writeIx++;
    cb->writeIx = (cb->writeIx % cb->size);

    return 1;
}

/**
 * @brief Function that allocates memory for a string.
 * @fn char *strAlloc(const char *str)
 *
 * @param str string to be allocated
 * @return pointer to the allocated string
 */

char *strAlloc(const char *str)
{
    int len = strlen(str);
    char *ptr = malloc(sizeof(char) * (len + 1));
    if (ptr == NULL)
        return NULL;

    strcpy(ptr, str);
    return ptr;
}

/**
 * @brief Function that gets a line from the buffer.
 * @fn char *cbuf_get(CircularBufferT *cb)
 *
 * @param cb pointer to the buffer
 * @return pointer to the line
 */

char *cbuf_get(CircularBufferT *cb)
{
    if (cb->readIx == cb->writeIx)
        return NULL; // Buffer is empty

    char *tmp = cb->lines[cb->readIx];
    cb->readIx++;
    cb->readIx = (cb->readIx % cb->size);
    return tmp;
}

/**
 * @brief Function that frees the buffer.
 * @fn void cbuf_free(CircularBufferT *cb)
 *
 * @param cb pointer to the buffer
 */

void cbuf_free(CircularBufferT *cb)
{
    if (cb->lines != NULL)
        free(cb->lines);
    cb->writeIx = 0;
    cb->readIx = 0;
    cb->size = 0;
    free(cb);
}

/**
 * @brief Function that parses arguments.
 * @fn bool parseArgs(int argc, char **argv, int *n, FILE **file)
 *
 * @param argc number of arguments
 * @param argv array of arguments
 * @param n pointer to the number of lines to be printed
 * @param file pointer to the file
 * @return 1 if successful, 0 if not
 */

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
            if (i + 1 == argc)
            {
                fprintf(stderr, "No argument after -n\n");
                return 0;
            }
            char *endptr;
            *n = (int)strtol(argv[++i], &endptr, 10);
            if (*endptr != '\0')
            {
                fprintf(stderr, "Wrong argument after -n\n");
                return 0;
            }
            if (*n < 0)
                return 0;
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
