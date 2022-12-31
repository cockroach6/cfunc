#ifndef _MEM_ROACH_H
#define _MEM_ROACH_H

#include "llist.h"

extern T *head;
void *my_malloc (size_t size);
void *my_calloc (size_t nelem, size_t elsize);
void *my_realloc (void *ptr, size_t size);
void my_free (void *ptr);

#endif
