/*Pointers (stack) pointing to
  constants (manufactured pointers).*/

int main()
{
  int *p;
  unsigned long i, addr = (unsigned long)&i;

  p = (int *)addr;
  i = *p;

  return 0;
}
