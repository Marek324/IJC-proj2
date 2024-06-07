/**
 * @file htab_clear.c
 * @brief Function that clears the hash table.
 * @author Marek Hric
 * @bug No known bugs.
 */

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

static void free_htab_items(struct htab_item *item);

/**
 * @brief Function that clears the hash table.
 * @fn void htab_clear(htab_t *t)
 *
 * @param t pointer to the hash table
 */

void htab_clear(htab_t *t)
{
    for (size_t i = 0; i < htab_bucket_count(t)-1; i++)
    {
        if (t->htab_items[i] != NULL)
        {
            free_htab_items(t->htab_items[i]);
        }
    }
    free(t->htab_items);
    t->size = 0;
    t->arr_size = 0;
}

/**
 * @brief Function that recursively frees the items in the hash table.
 *
 * @param item pointer to the item
 */

static void free_htab_items(struct htab_item *item)
{
    if (item->next != NULL)
        free_htab_items(item->next);

    free((void *)item->pair->key);
    free(item->pair);
    free(item);
}