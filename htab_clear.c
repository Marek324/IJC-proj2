#include "htab.h"
#include "htab_private.h"

void htab_clear(htab_t *t)
{
    if (t == NULL || t->arr_size == 0)
        return;

    for (size_t i = 0; i < t->arr_size; i++)
    {
        free_htab_items(t->htab_items[i]);
    }
    t->size = 0;
}

void free_htab_items(struct htab_item *item)
{
    if (item->next != NULL)
        free_htab_items(item->next);
    free(item->pair->key);
    free(item->pair);
    free(item);
}