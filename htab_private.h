/**
 * @file htab_private.h
 * @brief Private structures for the hash table.
 * @author Marek Hric
 */

#ifndef HTAB_PRIVATE_H__
#define HTAB_PRIVATE_H__

#include "htab.h"

/**
 * @struct htab_item
 * @brief structure representing the item in the hash table
 */

struct htab_item
{
    htab_pair_t *pair;
    struct htab_item *next;
};

/**
 * @struct htab
 * @brief structure representing the hash table
 */

struct htab
{
    size_t size;
    size_t arr_size;
    struct htab_item **htab_items;
};

#endif // HTAB_PRIVATE_H__
