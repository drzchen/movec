/*Pointers (stack) pointing to
  variables (stack).*/

void f_stack(int **p_addr)
{
  int x;
  *p_addr = &x;
}

int main()
{
  int ret;

  int *p;

  f_stack(&p);
  *p = ret; /*temporal error*/

  return 0;
}
