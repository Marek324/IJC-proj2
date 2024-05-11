/**
 * @file htab_bucket_count.c
 * @brief Function that returns the number of buckets in the hash table.
 * @author Marek Hric
 * @bug No known bugs.
 */

#include "htab.h"
#include "htab_private.h"

/**
 * @brief Function that returns the number of buckets in the hash table.
 * @fn size_t htab_bucket_count(const htab_t * t)
 *
 * @param t hash table pointer
 * @return size_t number of buckets in the hash table
 */
size_t htab_bucket_count(const htab_t *t)
{
    return t->arr_size;
}
