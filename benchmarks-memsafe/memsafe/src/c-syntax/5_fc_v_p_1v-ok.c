/*Function calls to variadic functions, with
  pointer parameters.*/

#include <stdarg.h>
void *vfunc(int n, ...)
{
  int i;
  void *p;

  va_list arg;
  va_start(arg, n);
  for(i = 1; i <= n; i++)
  {
    p = va_arg(arg, void*);
  }
  va_end(arg);

  return p;
}

int main()
{
  char *ret, ch;

  char str[20] = "string literal";
  char *p1 = str;

  ret = (char*)vfunc(2, p1, p1+10);
  ch = ret[9];

  return 0;
}

