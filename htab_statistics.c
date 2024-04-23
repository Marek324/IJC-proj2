/*
Marek Hric
FIT
priklad 2
23.4.2024
*/
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

    int *lens = calloc(htab_bucket_count(t), sizeof(int));
    if (lens == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        return;
    }

    for (size_t i = 0; i < htab_bucket_count(t); i++)
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

    free(lens);

    float avg = (float)sum / (float)htab_bucket_count(t);

    fprintf(stderr, "Minimum length: %d\n", min);
    fprintf(stderr, "Maximum length: %d\n", max);
    fprintf(stderr, "Average length: %f\n", avg);
}
