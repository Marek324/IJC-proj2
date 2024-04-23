/*
Marek Hric
FIT
priklad 2
23.4.2024
*/
#include "htab.h"
#include "htab_private.h"
#include <stdio.h>

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
