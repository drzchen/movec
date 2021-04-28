/*Pointers (stack) long overflow.*/

int main()
{
  int a[100];
  int ret = 0;
  int b[100];

  int *p = &ret;

  *(p+10) = ret; /*spatial error*/

  return 0;
}
