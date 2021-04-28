/*Pointers (stack) pointing to
  constants (manufactured pointers).*/

int main()
{
  unsigned long *p;
  unsigned long i, addr = (unsigned long)&i;

  p = (unsigned long *)addr;
  i = *(p+1); /*spatial error*/

  return 0;
}
