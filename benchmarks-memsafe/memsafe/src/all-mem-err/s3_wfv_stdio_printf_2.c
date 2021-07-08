/*Wrapper functions (variadic) in stdio.h: printf.*/
#include <stdio.h>
#include <stdlib.h>

void f(char *p)
{
  free(p);
}

int main()
{
  int i = 0;
  char *str1 = "Hello";
  char *str2 = (char *)malloc(10);
  str2[0] = '\0';
  f(str2);

  printf("%d %s %s\n", i, str1, str2); /*str2 temporal error*/

  return 0;
}
