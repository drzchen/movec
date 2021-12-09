#include <stdlib.h>

#ifndef N
#define N 10000
#endif

int main()
{
  int ret, **p;
  unsigned long i, j;
  for(i = 0; i < N; i++)
  {
    p = (int**)malloc(sizeof(int*));
    for(j = 0; j < N; j++)
    {
      *p = (int*)malloc(sizeof(int));
      ret = **p;

      free(*p);
    }
    free(p);
  }

  return 0;
}
