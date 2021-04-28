/*Object-level overflows in global variables.*/

int a[100];
int ret;
int b[100];

int main()
{
  int *p = &ret;

  *(p+10) = ret; /*spatial error*/

  return 0;
}
