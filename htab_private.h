#ifndef HTAB_PRIVATE_H__
#define HTAB_PRIVATE_H__

#include "htab.h"

struct htab
{
    int size;
    int arr_size;
    htab_item **htab_items;    
};

struct htab_item
{
    htab_pair_t pair;
    htab_item *next;
};

#endif // HTAB_PRIVATE_H__
