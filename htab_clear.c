/*
Marek Hric
FIT
priklad 2
23.4.2024
*/
#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

static void free_htab_items(struct htab_item *item);

void htab_clear(htab_t *t)
{
    for (size_t i = 0; i < htab_bucket_count(t); i++)
    {
        if (t->htab_items[i] != NULL)
        {
            free_htab_items(t->htab_items[i]);
        }
    }
    t->size = 0;
}

static void free_htab_items(struct htab_item *item)
{
    if (item->next != NULL)
        free_htab_items(item->next);

    free(item->pair);
    free(item);
}