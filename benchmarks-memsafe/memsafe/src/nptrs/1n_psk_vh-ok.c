#include <stdlib.h>

#ifndef N
#define N 100000000
#endif

int main()
{
  int ret, *p;
  unsigned long i;
  for(i = 0; i < N; i++)
  {
    p = (int*)malloc(sizeof(int));
    ret = *p;

    free(p);
  }

  return 0;
}
