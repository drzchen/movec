/*Subscripts.*/

int main()
{
  int ret;
  int *p = &ret;

  ret = p[0];
  ret = (++p)[0]; /*spatial error*/

  return 0;
}

