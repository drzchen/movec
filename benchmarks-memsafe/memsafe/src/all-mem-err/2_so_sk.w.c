/*Sub-object overflows in stack.*/

struct st
{
  int a1[2];
  int a2[2][3];
};

int main()
{
  int ret;

  struct st s;
  int *p1;

  /*one dimensional*/
  p1 = s.a1;
  p1[0] = ret;
  *(p1+2) = ret; /*sub-object spatial error*/

  return 0;
}
