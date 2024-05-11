/**
 * @file htab_free.c
 * @brief Function that frees the hash table.
 * @author Marek Hric
 * @bug No known bugs.
 */

#include "htab.h"
#include "htab_private.h"
#include <stdlib.h>

/**
 * @brief Function that frees the hash table.
 * It calls htab_clear() to clear the hash table items and then frees the hash table itself.
 * @fn void htab_free(htab_t *t)
 *
 * @param t pointer to the hash table
 */

void htab_free(htab_t *t)
{
    htab_clear(t);
    free(t);
}
