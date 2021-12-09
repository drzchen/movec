#include <stdlib.h>

#ifndef N
#define N 10000
#endif

int **p;

void check(unsigned long i, unsigned long n)
{
  int ret;
  *p = &ret;
  ret = **p;
  
  if(n <= 1)
  {
    if(i == (N-1)) *(*p+1) = ret; /*spatial error*/
    return;
  }
  else check(i, n-1); /*recursive call*/
}

int main()
{
  int ret;
  unsigned long i;
  for(i = 0; i < N; i++)
  {
    p = (int**)malloc(sizeof(int*));
    check(i, N);
    free(p);
  }

  return 0;
}
