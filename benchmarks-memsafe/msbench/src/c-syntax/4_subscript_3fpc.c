/*Subscripts.*/

int *func(int *ptr)
{
  return ptr;
}

int main()
{
  int ret;
  int *(*fp)(int *) = func;
  int *p = &ret;

  ret = fp(p-1)[1];
  ret = (1 + fp(p-1) + 1)[0]; /*spatial error*/

  return 0;
}

