#include <stdlib.h>

#ifndef N
#define N 10000
#endif

void check(int **p, unsigned long n)
{
  int ret;
  *p = &ret;
  ret = **p;
  
  if(n <= 1)
    return;
  else check(p, n-1); /*recursive call*/
}

int main()
{
  int ret, *p;
  check(&p, N);

  return 0;
}
