/*Pointers (stack) pointing to
  constants (arrays of integers in structs).*/

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
  ret = p1[0];
  ret = *(p1+8); /*spatial error*/

  return 0;
}
