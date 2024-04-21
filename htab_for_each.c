#include "htab.h"
#include "htab_private.h"

void htab_for_each(const htab_t *t, void (*f)(htab_pair_t *data)){
    for (size_t i = 0; i < t->arr_size; i++)
    {
        struct htab_item *itemPtr = t->htab_items[i];
        while (itemPtr != NULL)
        {
            f(&(itemPtr->pair));
            itemPtr = itemPtr->next;
        }
        
    }
    
}
