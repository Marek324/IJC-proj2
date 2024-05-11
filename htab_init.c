/**
 * @file htab_init.c
 * @brief Function that initializes the hash table.
 * @author Marek Hric
 * @bug No known bugs.
 */

#include <stdlib.h>
#include "htab.h"
#include "htab_private.h"

/**
 * @brief Function that initializes the hash table.
 * @fn htab_t *htab_init(const size_t n)
 *
 * @param n number of buckets
 * @return pointer to the hash table
 */

htab_t *htab_init(const size_t n)
{
    htab_t *htab = (htab_t *)malloc(sizeof(htab_t));
    if (htab == NULL)
    {
        return NULL;
    }
    htab->size = 0;
    htab->arr_size = n;
    htab->htab_items = (struct htab_item **)malloc(sizeof(struct htab_item *) * n);
    if (htab->htab_items == NULL)
    {
        free(htab);
        return NULL;
    }
    for (size_t i = 0; i < n; i++)
    {
        htab->htab_items[i] = NULL;
    }

    return htab;
}
