/**
 * @file htab_size.c
 * @brief Function that returns the number of items in the hash table.
 * @author Marek Hric
 * @bug No known bugs.
 */

#include "htab.h"
#include "htab_private.h"

/**
 * @brief Function that returns the number of items in the hash table.
 * @fn size_t htab_size(const htab_t *t)
 *
 * @param t hash table pointer
 * @return size_t number of items in the hash table
 */

size_t htab_size(const htab_t *t)
{
    return t->size;
}
