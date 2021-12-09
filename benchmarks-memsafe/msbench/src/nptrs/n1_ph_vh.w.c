#include <stdlib.h>

#ifndef N
#define N 100000000
#endif

int main()
{
  int *a = (int*)malloc(sizeof(int));

  int ret, **p;
  unsigned long i;
  for(i = 0; i < N; i++)
  {
    p = (int**)malloc(sizeof(int*));
    *p = a;
    ret = **p;

    if(i == (N-1)) *(*p+1) = ret; /*spatial error*/
    free(p);
  }

  free(a);

  return 0;
}
