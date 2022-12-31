#ifndef _LLIST_ROACH_H
#define _LLIST_ROACH_H

#include <stdio.h>
#include <stdlib.h>
#define T llist

typedef struct T {
  size_t size;
  int free;
  struct T *next;
} T;

int llist_len (T *head);
void llist_add (T **head, T *node);
void llist_show (T *head);
void print_array (int *arr, size_t size);
#endif
