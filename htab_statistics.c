#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "htab.h"
#include "htab_private.h"

void htab_statistics(const htab_t *t)
{
    int max = 0;
    int min = INT_MAX;
    int sum = 0;

    int *lens = calloc(t->arr_size, sizeof(int));
    if (lens = NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        return;
    }

    for (size_t i = 0; i < t->arr_size; i++)
    {
        struct htab_item *itemPtr = t->htab_items[i];
        while (itemPtr != NULL)
        {

            lens[i]++;

            itemPtr = itemPtr->next;
        }

        sum += lens[i];

        if (lens[i] > max)
            max = lens[i];
        else if (lens[i] < min)
            min = lens[i];
    }

    float avg = (float) sum / (float) t->arr_size;

    fprintf(stderr, "Minimum length: %d\n", min);
    fprintf(stderr, "Maximum length: %d\n", max);
    fprintf(stderr, "Average length: %f\n", avg);
}
