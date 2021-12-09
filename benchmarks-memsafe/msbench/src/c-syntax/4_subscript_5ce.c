/*Subscripts.*/

int main()
{
  int ret;

  int *p, *q;
  p = q = &ret;
  ret = ((p == q)?p:q++)[0];
  ret = ((p == q)?p+1:q-1)[0]; /*spatial error*/
  ret = ((p == q)?q:q+1)[0];

  return 0;
}

