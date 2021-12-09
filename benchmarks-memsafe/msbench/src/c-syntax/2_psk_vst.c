/*Pointers (stack) pointing to
  variables (static).*/

void f_static(int **p_addr)
{
  static int x;
  *p_addr = &x;
}

int main()
{
  int ret;

  int *p;

  f_static(&p);
  ret = *p;
  ret = p[1]; /*spatial error*/

  return 0;
}
