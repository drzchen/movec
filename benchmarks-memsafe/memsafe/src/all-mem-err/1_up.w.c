/*Uninitialized pointers.*/
#include <stdio.h>
int main()
{
  unsigned long *p, i;

  *p = i; /*uninitialized pointer error*/

  return 0;
}
