#include "htab.h"
#include "htab_private.h"

htab_pair_t *htab_find(const htab_t *t, htab_key_t key)
{
    size_t hash = htab_hash_function(key) % t->arr_size;
    struct htab_item *itemPtr = t->htab_items[hash];

    htab_pair_t *ret = NULL;

    while (itemPtr != NULL)
    {

        if (key == itemPtr->pair->key)
        {
            ret = itemPtr->pair;
        }

        itemPtr = itemPtr->next;
    }

    return ret;
}