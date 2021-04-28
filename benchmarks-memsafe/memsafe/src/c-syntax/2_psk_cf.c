/*Pointers (stack) pointing to
  constants (function).*/
#include <stdio.h>

void foo()
{
  printf("call foo.\n");
}

int main()
{
  int *p1 = (int *)foo;
  int *p2 = p1 + 1;
  void (*p3)() = (void (*)())p1;
  void (*p4)() = (void (*)())p2;

  p3();
  (*p4)(); /*spatial error*/

  return 0;
}

