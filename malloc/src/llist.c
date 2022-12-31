#include "llist.h"
#include <stdio.h>
#include <stdlib.h>

#define T llist

T
*llist_node (size_t size)
{
  T *node = malloc (sizeof (T));
  if (node == NULL) {
    fprintf(stderr, "err: could not allocate memory\n");
    return NULL;
  }
  node->size = size;
  node->next = NULL;
  return node;
}

void
llist_add (T **head, T *node)
{
  T *headp = *head;

  if (!(*head)) {
    *head = node;
    return ;
  }

  while (headp->next) {
    headp = headp->next;
  }
  headp->next = node;
}

void
llist_show (T *head)
{
  T *headp = head;

  printf("List : ");
  while (headp) {
    printf("%d ", headp->size);
    headp = headp->next;
  }
  printf("\n");
}

int
llist_len (T *head)
{
  T *headp = head;
  int i = 0;

  while (headp) {
    headp = headp->next;
    ++i;
  }
  return i;
}

void
print_array (int *arr, size_t size)
{
  printf("Array: ");
  for (size_t i = 0; i < size; ++i) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

#undef T