/**
 * @file htab_lookup_add.c
 * @brief Function that looks up the key in the hash table and if it is not found, it adds it to the hash table.
 * @author Marek Hric
 * @bug No known bugs.
 */

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

/**
 * @brief Function that looks up the key in the hash table and if it is not found, it adds it to the hash table.
 * @fn htab_pair_t *htab_lookup_add(htab_t *table, htab_key_t key)
 *
 * @param table pointer to the hash table
 * @param key key to be looked up
 * @return htab_pair_t* pointer to the item with the key
 */

htab_pair_t *htab_lookup_add(htab_t *table, htab_key_t key)
{
    htab_pair_t *pairPtr = htab_find(table, key);
    if (pairPtr != NULL)
        pairPtr->value++;

    else
    {
        pairPtr = malloc(sizeof(htab_pair_t));
        if (pairPtr == NULL)
            return NULL;

        char *newKey = malloc(strlen(key) + 1);
        if (newKey == NULL)
        {
            free(pairPtr);
            return NULL;
        }

        pairPtr->key = strcpy(newKey, key);
        pairPtr->value = 1;

        struct htab_item *newItem = malloc(sizeof(struct htab_item));
        if (newItem == NULL)
        {
            free(pairPtr);
            free(newKey);
            return NULL;
        }

        newItem->pair = pairPtr;
        newItem->next = NULL;

        size_t hash = htab_hash_function(key) % table->arr_size;

        struct htab_item *itemTmp = table->htab_items[hash];
        if (itemTmp == NULL)
        {
            table->htab_items[hash] = newItem;
        }
        else
        {
            while (itemTmp->next != NULL)
            {
                itemTmp = itemTmp->next;
            }
            itemTmp->next = newItem;
        }
        table->size++;
    }
    return pairPtr;
}
