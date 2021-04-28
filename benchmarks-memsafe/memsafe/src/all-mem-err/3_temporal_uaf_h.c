/*Use-after-free of heap memory.*/
#include <stdlib.h>
#include <stdio.h>

int main()
{
  int *n, *r;
  int ret;

  n = malloc(sizeof(int)*5);
  r = n;

  free(r);
  ret = n[0]; /*temporal error*/

  return 0;
}
