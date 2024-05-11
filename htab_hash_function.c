/**
 * @file htab_hash_function.c
 * @brief Function that generates a hash value from a string.
 * @author Marek Hric
 * @bug No known bugs.
 */

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Function that generates a hash value from a string.
 * @fn size_t htab_hash_function(const char *str)
 *
 * @param str string to be hashed
 * @return size_t hash value
 */

size_t htab_hash_function(const char *str)
{
    uint32_t h = 0; // musí mít 32 bitů
    const unsigned char *p;
    for (p = (const unsigned char *)str; *p != '\0'; p++)
        h = 65599 * h + *p;
    return h;
}
