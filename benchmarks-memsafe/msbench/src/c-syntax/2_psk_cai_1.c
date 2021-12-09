/*Pointers (stack) pointing to
  constants (arrays of integers).*/

int main()
{
  int ret;

  int a1[2] = {1,2};
  int *p1;

  /*one dimensional*/
  p1 = a1;
  ret = p1[1];
  ret = *(p1 + 2); /*spatial error*/

  return 0;
}
