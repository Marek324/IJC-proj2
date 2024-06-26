/**
 * @file htab_erase.c
 * @brief Function that erases the item with the given key from the hash table.
 * @author Marek Hric
 * @bug No known bugs.
 */

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

/**
 * @brief Function that erases the item with the given key from the hash table.
 * @fn bool htab_erase(htab_t *t, htab_key_t key)
 *
 * @param t pointer to the hash table
 * @param key key of the item to be erased
 * @return bool true if the item was erased, false otherwise
 */

bool htab_erase(htab_t *t, htab_key_t key)
{
    size_t hash = htab_hash_function(key) % htab_bucket_count(t);
    struct htab_item *itemPtr = t->htab_items[hash];

    struct htab_item *prev = NULL;
    bool ret = 0;

    while (itemPtr != NULL)
    {
        if (strcmp(key, itemPtr->pair->key) == 0)
        {
            ret = 1;
            prev->next = itemPtr->next;
            free(itemPtr->pair);
            free(itemPtr);
            t->size--;
            break;
        }
        prev = itemPtr;
        itemPtr = itemPtr->next;
    }

    return ret;
}