/*Null pointers.*/
#include <stdio.h>
int main()
{
  unsigned long *p = NULL, i;

  i = *p; /*null pointer error*/

  return 0;
}
