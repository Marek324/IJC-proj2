#include "htab.h"
#include "htab_private.h"

size_t htab_size(const htab_t *t)
{
    return t->size;
}
