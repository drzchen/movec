/*Segment errors: invalid dereference.*/
#include <stdio.h>

void foo()
{
  printf("call foo.\n");
}

char *func(char *s)
{
  return s;
}

int main()
{
  void (*p)() = foo;
  char *s = func(p);
  char ch = s[0]; /*segment error*/

  return 0;
}

