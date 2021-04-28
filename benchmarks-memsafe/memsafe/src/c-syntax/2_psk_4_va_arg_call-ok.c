/*Pointers (stack) pointing to
  va_arg() function return values.*/

int a[2] = {1, 2};

#include <stdarg.h>
int *vfunc(int n, ...)
{
  int *vp[3];
  int i;

  va_list arg;
  va_start(arg, n);
  for(i=0; i<3; i++)
    vp[i] = va_arg(arg, int*);
  va_end(arg);

  return vp[n];
}

int main()
{
  int ret;

  int *p;

  p = vfunc(2, a, &a, &a[1]);
  ret = *p;

  return 0;
}
