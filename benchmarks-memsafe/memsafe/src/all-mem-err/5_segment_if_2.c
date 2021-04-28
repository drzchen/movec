/*Segment errors: invalid free.*/
#include <stdlib.h>

void f_stack(int **p_addr)
{
  int x;
  *p_addr = &x;
}

int main()
{
  int *p1, *p2;

  f_stack(&p1);
  p2 = p1;
  free(p2); /*segment error*/

  return 0;
}
