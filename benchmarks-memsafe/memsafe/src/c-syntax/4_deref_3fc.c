/*Dereferences.*/

int *func(int *ptr)
{
  return ptr;
}

int main()
{
  int ret;

  ret = *func(&ret);
  ret = *func(&ret+1); /*spatial error*/

  return 0;
}

