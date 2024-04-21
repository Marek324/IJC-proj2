#ifndef HTAB_PRIVATE_H__
#define HTAB_PRIVATE_H__

#include "htab.h"

struct htab_item
{
    htab_pair_t *pair;
    struct htab_item *next;
};

struct htab
{
    size_t size;     // pocet zaznamov
    size_t arr_size; // pocet prvkov htab_items
    struct htab_item **htab_items;
};

#endif // HTAB_PRIVATE_H__
