/*Definitions of arrays (structure values).*/

typedef struct st {
  int i;
  int *p;
} st;

int *f_p(int *ptr)
{
  return ptr;
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

  ret = obj[2][0].p[9];
  ret = obj[2][0].p[10]; /*spatial error*/

  return 0;
}


