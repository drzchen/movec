/*Temporal errors: double free.*/

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
  int *p1, *p2;

  allocate(&p1);
  p2 = p1;
  free(p1);
  free(p2); /*temporal error*/

  return 0;
}
