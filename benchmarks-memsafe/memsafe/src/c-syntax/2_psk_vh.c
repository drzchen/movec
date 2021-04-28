/*Pointers (stack) pointing to
  variables (heap).*/

#include <stdlib.h>

int *malloc_int(int x)
{
  return (int*)malloc(x*sizeof(int));
}

void allocate(int **addr)
{
  *addr = malloc_int(2);
}

int main()
{
  int lhs;

  int *p1;

  allocate(&p1);
  lhs = *p1;
  lhs = p1[1];
  lhs = p1[2]; /*spatial error*/

  free(p1);

  return 0;
}
