#include <unistd.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "mem.h"
#include "llist.h"

#define META_SIZE sizeof (T)

T *head;

T
*get_block_ptr (void *ptr)
{
  return (T *)ptr - 1;
}

static T
*find_free_block (T *head, size_t size)
{
  T *headp = head;

  while (headp && !(headp->free && headp->size >= size)) {
    headp = headp->next;
  }
  return headp;
}

static T
*request_space (T **head, size_t size)
{
  T *block;
  void *request;

  block = sbrk (0);
  request = sbrk (META_SIZE + size);
  if (request == (void*) -1) {
    return NULL;
  }

  llist_add (head, block);

  block->size = size;
  block->next = NULL;
  block->free = 0;
  return block;
}

void
*my_malloc (size_t size)
{
  T *block;

  if (size <= 0) {
    return NULL;
  }

  block = find_free_block (head, size);
  if (block == NULL) {
    block = request_space (&head, size);
    if (!block) {
      return NULL;
    }
  }
  return (block + 1);
}

void
*my_calloc (size_t nelem, size_t elsize)
{
  size_t size = nelem * elsize;
  void *ptr = my_malloc (size);
  memset (ptr, 0, size);
  return ptr;
}

void
*my_realloc (void *ptr, size_t size)
{
  void *new_ptr;

  if (!ptr) {
    return my_malloc (size);
  }

  T *block = get_block_ptr (ptr);
  if (block->size >= size) {
    /* We have enough space. Could free some
       once we implement split. **/
    return ptr;
  }

  new_ptr = my_malloc (size);
  memcpy (new_ptr, ptr, block->size);
  my_free (ptr);
  return new_ptr;
}

void
my_free (void *ptr)
{
  if (!ptr)
    return ;

  T *block = get_block_ptr (ptr);
  assert (block->free == 0);
  block->free = 1;
}
