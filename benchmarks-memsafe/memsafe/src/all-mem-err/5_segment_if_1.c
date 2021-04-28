/*Segment errors: invalid free.*/
#include <stdlib.h>

int main()
{
  int x, *p1, *p2;

  p1 = &x;
  p2 = p1;
  free(p2); /*segment error*/

  return 0;
}
