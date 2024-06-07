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

htab_pair_t *htab_lookup_add(htab_t *table, htab_key_t key) {
    htab_pair_t *newPair = htab_find(table, key);
    if (newPair != NULL) {
        newPair->value++;
    }
    else {
        struct htab_item *newItem = malloc(sizeof(struct htab_item));
        if (newItem == NULL) {
            return NULL;
        }
        newPair = malloc(sizeof(htab_pair_t));
        if (newPair == NULL) {
            free(newItem);
            return NULL;
        }
        char *tmpKey = malloc(strlen(key) + 1);
        if (tmpKey == NULL) {
            free(newItem);
            free(newPair);
            return NULL;
        }
        newPair->key = strcpy(tmpKey, key);
        newPair->value = 1;
        newItem->pair = newPair;
        newItem->next = NULL;
        int index = htab_hash_function(key) % table->arr_size;
        struct htab_item *add = table->htab_items[index];
        if (add == NULL) {
            table->htab_items[index] = newItem;
        }
        else {
            while (add->next != NULL) {
                add = add->next;
            }
            add->next = newItem;
        }
        table->size++;
    }
    return newPair;
}