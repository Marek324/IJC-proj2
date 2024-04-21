#include "htab.h"
#include "htab_private.h"

bool htab_erase(htab_t *t, htab_key_t key)
{
    size_t hash = htab_hash_function(key) % t->arr_size;
    struct htab_item *itemPtr = t->htab_items[hash];

    struct htab_item *prev = NULL;
    bool ret = 0;

    while (itemPtr != NULL)
    {
        if (key == itemPtr->pair->key)
        {
            ret = 1;
            prev->next = itemPtr->next;
            free(itemPtr->pair->key);
            free(itemPtr->pair);
            free(itemPtr);
            break;
        }
        prev = itemPtr;
        itemPtr = itemPtr->next;
    }

    return ret;
}