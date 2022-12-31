#include "roach.h"
#include "mem.h"

/* Code was copied from this tutorial and
   slightly modified.
   Link https://danluu.com/malloc-tutorial **/

void
test2 (void)
{
  size_t size1 = 10;
  size_t size2 = 8;
  size_t size3 = 8;
  int *arr1, *arr2, *arr3;

  arr1 = my_malloc (size1);
  if (arr1 == NULL) {
    fprintf(stderr, "err: my_malloc failed\n");
    exit (1);
  }

  /* free previosly allocated memory to make
  sure my_free() works correctly.  */
  my_free (arr1);

  arr2 = my_malloc (size2);
  if (arr2 == NULL) {
    fprintf(stderr, "err: my_malloc failed\n");
    exit (1);
  }


  print_array (arr1, size1);

  llist_show (head);
  printf("list len: [%d]\n", llist_len (head));
}

void
test3 (void)
{
  char *str = my_malloc (10);
  if (!str) {
    fprintf(stderr, "err: my_malloc failed\n");
    exit (1);
  }

  strcpy (str, "hello");

  my_realloc (str, 20);

  printf("%s\n", str);
}

int
main (void)
{
  test3 ();
  return 0;
}