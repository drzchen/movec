/*Segment confusion errors: invalid dereference.*/
#include "header.h"

int main()
{
  void (*p)() = foo;
  char *s = func(p);
  char ch = s[0]; /*segment confusion error*/

  return 0;
}
