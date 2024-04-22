#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key)
{
    htab_pair_t *pairPtr = htab_find(t, key);
    if (pairPtr == NULL)
    {
        pairPtr = malloc(sizeof(htab_pair_t));
        if (pairPtr == NULL)
            return NULL;
        pairPtr->key = (htab_key_t)malloc(strlen(key) + 1);
        pairPtr->key = key;
        if (pairPtr->key == NULL)
        {
            free(pairPtr);
            return NULL;
        }

        size_t hash = htab_hash_function(key) % t->arr_size;
        struct htab_item *itemTmp = t->htab_items[hash];
        while (itemTmp->next != NULL)
        {
            itemTmp = itemTmp->next;
        }

        itemTmp->next = (struct htab_item *)malloc(sizeof(struct htab_item));
        if (itemTmp->next == NULL)
        {
            free(pairPtr->key);
            free(pairPtr);
            return NULL;
        }

        itemTmp = itemTmp->next;
        itemTmp->next = NULL;
        itemTmp->pair = pairPtr;
        t->size++;
    } else {
        pairPtr->value++;
    }
    return pairPtr;
}
