/*Pointers (stack) pointing to
  conditional expressions.*/

int a[2] = {1, 2};
int *pa = a;

int main()
{
  int ret;

  int *p;

  p = a==pa ? a:a+1;
  ret = *p;
  ret = p[1];

  p = pa==0 ? a:++pa;
  ret = *p;
  ret = p[1]; /*spatial error*/

  return 0;
}
