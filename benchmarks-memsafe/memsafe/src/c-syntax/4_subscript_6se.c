/*Subscripts.*/

int main()
{
  int ret;
  int *p = &ret;
  int i = 0;

  ret = (p+(i++))[0];
  ret = (p+(++i))[-2];
  ret = (p+i)[-1]; /*spatial error*/

  return 0;
}

