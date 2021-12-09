/*Uninitialized pointers.*/
#include <stdio.h>
int main()
{
  unsigned long *p, i;

  i = *p; /*uninitialized pointer error*/

  return 0;
}
