/*Wrapper functions in stdlib.h: free.*/
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int *n, *r;
  int ret;

  n = malloc(sizeof(int)*5);
  r = n + 1;

  free(r); /*spatial error*/

  return 0;
}
