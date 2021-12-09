#include <stdlib.h>

#define N 80
#define SIZE 128*1024*1024 /* 128MB */

int *gp;

int main()
{
  int i, *p[N];

  for(i = 0; i < N; i++)
  {
    p[i] = (int*)malloc(SIZE);
    *p[i] = i;
    if(i==N/2) gp = p[i]; /* Remember a freed object */
    free(p[i]);
  }

  for(i = 0; i < N; i++)
  {
    p[i] = (int*)malloc(SIZE); /* Reallocate memory */
    *p[i] = i;
  }

  i = *gp; /* Use-after-free error: */
           /* ASan Valgrind cannot detect it. */
           /* MOVEC can detect it. */

  for(i = 0; i < N; i++)
  {
    free(p[i]);
  }

  return 0;
}
