/*Segment confusion errors: invalid dereference.*/
#include <stdio.h>

void foo()
{
  printf("call foo.\n");
}

char *func(char *c)
{
  return c;
}

int main()
{
  void (*p)() = foo;
  char *s = func(p);
  char ch = s[0]; /*segment confusion error*/

  return 0;
}
