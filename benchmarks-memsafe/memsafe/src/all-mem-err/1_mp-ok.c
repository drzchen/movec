/*Manufactured pointers.*/

int main()
{
  unsigned long *p;
  unsigned long i, addr = (unsigned long)&i;

  p = (unsigned long *)addr;
  i = *p;
  *p = i;

  return 0;
}
