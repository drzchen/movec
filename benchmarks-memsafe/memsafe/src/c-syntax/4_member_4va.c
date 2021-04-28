/*Member expressions.*/

typedef struct st {
  int i;
  int j;
  struct st *next;
} st;

/*nested structure type*/
typedef struct stn {
  st st1;
  st st2;
} stn;

#include <stdarg.h>
void vfunc(int n, ...)
{
   int ret;

   int i;
   va_list arg;
   va_start(arg, n);
   for(i=0; i<n; i++)
     ret = va_arg(arg, st*)->i; /*spatial error*/
   va_end(arg);
}

int main()
{
  st s2 = {2, 3, &s2-1};
  st s1 = {0, 1, &s2};
  stn sn1 = {s1, s2};
  st *sp1 = &s1;
  st *sp2 = (st*)&sn1+1;
  st *sp3 = (st*)&sn1+2;
  st *sp4 = &sn1.st2;

  vfunc(4, sp1, sp2, sp3, sp4);

  return 0;
}

