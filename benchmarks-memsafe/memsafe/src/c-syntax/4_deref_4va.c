/*Dereferences.*/

#include <stdarg.h>
void vfunc(int n, ...)
{
   int ret;

   int i;
   va_list arg;
   va_start(arg, n);
   for(i=0; i<n; i++)
     ret = *va_arg(arg, int*); /*spatial error*/
   va_end(arg);
}

int main()
{
  int ret;
  int *p = &ret;

  vfunc(3, p, &ret, p+1);

  return 0;
}

