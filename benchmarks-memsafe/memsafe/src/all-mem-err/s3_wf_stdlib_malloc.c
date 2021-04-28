/*Wrapper functions in stdlib.h: malloc.*/
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int *n, *r;
  int ret;

  n = malloc(sizeof(int)*5);
  r = n;

  ret = r[4];
  ret = *(r+5);  /*spatial error*/

  free(n);

  return 0;
}
