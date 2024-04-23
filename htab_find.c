/*
Marek Hric
FIT
priklad 2
23.4.2024
*/
#include "htab.h"
#include "htab_private.h"

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