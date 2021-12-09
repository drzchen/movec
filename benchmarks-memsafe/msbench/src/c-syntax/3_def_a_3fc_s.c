/*Definitions of arrays (function return values: structures).*/

typedef struct st {
  int i;
  int *p;
} st;

int *f_p(int *ptr)
{
  return ptr;
}

st *element_st2(st (*ptr)[3], int i)
{
  return ptr[i];
}

int main()
{
  int ret;
  int i = 0, j = 1, k = 2;
  int *p1 = &i, *p2 = &j, *p3 = &k;
  int array[10];
  st obj[4][3] = {{{0, p1},         {1, p2+1},    {2, ++p3}},
                  {{3, array},      {4, &j},      {5, &k}},
                  {{6, f_p(array)}, {7, f_p(&j)}, {8, f_p(p1)}} };
  st *ret_ps;

  ret_ps = element_st2(obj, 2);
  ret = *ret_ps->p;
  ret = *(ret_ps->p + 9);
  ret = ret_ps->p[10]; /*spatial error*/

  return 0;
}
