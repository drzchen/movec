/*Pointers (stack) pointing to
  constants (arrays of integers).*/

int main()
{
  int ret;

  int a2[2][3] = {5,6,7,8,9};
  int (*p2)[3];

  /*two dimensional*/
  p2 = a2+1;
  ret = p2[0][0];
  ret = p2[0][3]; /*spatial error*/

  return 0;
}
