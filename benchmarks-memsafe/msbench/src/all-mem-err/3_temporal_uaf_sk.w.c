/*Use-after-free of stack memory.*/
#include <stdlib.h>
#include <stdio.h>

void f_stack(int **p_addr)
{
  int x;
  *p_addr = &x;
}

int main()
{
  int *n;
  int ret;

  f_stack(&n);

  n[0] = ret; /*temporal error*/

  return 0;
}
