/*Segment errors: invalid dereference.*/
#include <stdio.h>

void foo()
{
  printf("call foo.\n");
}

int main()
{
  char ch;
  void (*fp)() = foo;
  char *p = (char *)foo;

  (*fp)();
  ch = *p; /*segment error*/
  return 0;
}

