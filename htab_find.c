/**
 * @file htab_find.c
 * @brief Function that finds the item with the given key in the hash table.
 * @author Marek Hric
 * @bug No known bugs.
 */

#include "htab.h"
#include "htab_private.h"

/**
 * @brief Function that finds the item with the given key in the hash table.
 * @fn htab_pair_t *htab_find(const htab_t *t, htab_key_t key)
 *
 * @param t pointer to the hash table
 * @param key key of the item to be found
 * @return htab_pair_t* pointer to the item if found, NULL otherwise
 */

htab_pair_t *htab_find(const htab_t *t, htab_key_t key)
{
    size_t hash = htab_hash_function(key) % htab_bucket_count(t);
    struct htab_item *itemPtr = t->htab_items[hash];

    htab_pair_t *ret = NULL;

    while (itemPtr != NULL)
    {

        if (strcmp(key, itemPtr->pair->key) == 0)
        {
            ret = itemPtr->pair;
        }

        itemPtr = itemPtr->next;
    }

    return ret;
}