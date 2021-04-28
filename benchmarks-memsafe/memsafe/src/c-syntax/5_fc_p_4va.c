/*Function calls to non-variadic functions, with
  pointer parameters.*/

int *get_p(int *p)
{
  return p;
}

#include <stdarg.h>
void vfunc(int n, ...)
{
  int *p1, *p2, *p3, i;

  va_list arg;
  va_start(arg, n);
  p1 = get_p(va_arg(arg, int*));
  p2 = get_p(va_arg(arg, int*));
  p3 = get_p(va_arg(arg, int*));
  i = p1[0];
  i = p2[1]; /*spatial error*/
  i = p3[0];
  va_end(arg);
}

int main()
{
  int ai[5];
  vfunc(2, ai, ai+4, ai+4);

  return 0;
}
