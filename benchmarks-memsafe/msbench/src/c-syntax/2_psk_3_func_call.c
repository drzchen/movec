/*Pointers (stack) pointing to
  function return values.*/

int a[2] = {1, 2};

int *f1()
{
  return a;
}

int main()
{
  int ret;

  int *p = f1();

  ret = *p;
  ret = p[1];
  ret = *(p+2); /*spatial error*/

  return 0;
}
