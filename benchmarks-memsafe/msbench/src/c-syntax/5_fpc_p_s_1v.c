/*Function pointer (with parameters) calls to non-variadic functions, with
  structure parameters.*/

typedef struct {
  int m1;
  int *p1;
  char m2;
  char *p2;
  double m3;
  double *p3;
} st;

st get_st_i(int index, st s1, st s2)
{
  int i;
  char c;
  double d;

  i = *s1.p1;
  c = *s1.p2;
  d = *s1.p3;

  i = s2.p1[0];
  c = s2.p2[0];
  d = s2.p3[0];

  if(index == 0) return s1;
  else return s2;
}

st (*fp)(int, st, st) = get_st_i;

int main()
{
  st ret;

  int ai[5], i;
  char ac[5], c;
  double ad[5], d;
  st st1, st2;
  st1.p1 = ai;
  st1.p2 = (char*)&ac;
  st1.p3 = &ad[0];
  st2.p1 = st1.p1+4;
  st2.p2 = (char*)&ac;
  st2.p3 = &ad[0];

  ret = fp(1, st1, st2);
  i = ret.p1[0];
  i = ret.p1[1]; /*spatial error*/

  return 0;
}
