/*Subscripts.*/

int *func(int *ptr)
{
  return ptr;
}

int main()
{
  int ret;

  ret = func(&ret)[0];
  ret = func(&ret+1)[0]; /*spatial error*/

  return 0;
}

