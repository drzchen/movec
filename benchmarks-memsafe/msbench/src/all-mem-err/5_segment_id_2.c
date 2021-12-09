/*Segment errors: invalid dereference.*/
#include <stdio.h>

void foo()
{
  printf("call foo.\n");
}

int main()
{
  char ch;
  char *p = &ch;
  void (*fp)() = (void (*)())p;

  (*fp)(); /*segment error*/
  return 0;
}

