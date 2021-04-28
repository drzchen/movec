/*Pointers (stack) pointing to
  variables (stack).*/

int main()
{
  int ret;

  int *p = &ret;

  ret = *(p+1); /*spatial error*/

  return 0;
}
