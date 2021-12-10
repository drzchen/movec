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

    free(p);
  }

  free(a);

  return 0;
}
