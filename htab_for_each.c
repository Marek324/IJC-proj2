/**
 * @file htab_for_each.c
 * @brief Function that iterates through the hash table and applies the function f to each item.
 * @author Marek Hric
 * @bug No known bugs.
 */

#include "htab.h"
#include "htab_private.h"
#include <stdio.h>

/**
 * @brief Function that iterates through the hash table and applies the function f to each item.
 * @fn void htab_for_each(const htab_t *t, void (*f)(htab_pair_t *data))
 *
 * @param t pointer to the hash table
 * @param f pointer to the function to be applied to each item
 */

void htab_for_each(const htab_t *t, void (*f)(htab_pair_t *data))
{
    for (size_t i = 0; i < htab_bucket_count(t); i++)
    {
        struct htab_item *itemPtr = t->htab_items[i];
        while (itemPtr != NULL)
        {
            htab_pair_t *data = itemPtr->pair;
            f(data);
            itemPtr = itemPtr->next;
        }
    }
}
