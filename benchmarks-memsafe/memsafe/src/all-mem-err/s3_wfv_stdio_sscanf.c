/*Wrapper functions (variadic) in stdio.h: sscanf.*/
#include <stdio.h>

int main()
{
  int i;
  char ch;

  sscanf("1 0\n", "%d %d", &i, (int*)&ch); /*&ch spatial error*/

  return 0;
}
