/*Subscripts.*/

int main()
{
  int ret;
  register int *p = &ret;

  ret = p[0];
  ret = p[1]; /*spatial error*/

  return 0;
}

