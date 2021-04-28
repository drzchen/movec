/*Memory leaks.*/
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int *m, *n, *r;
  int ret;

  m = malloc(sizeof(int));
  n = malloc(sizeof(int)*5);
  free(n);

  r = n;
  n = m;
  m = r;

  printf("swap m n.\n");

  n = NULL; /*memory leak*/

  printf("terminating.\n");

  return 0;
}
