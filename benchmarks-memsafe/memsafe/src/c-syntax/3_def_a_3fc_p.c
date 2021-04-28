/*Definitions of arrays (function return values: pointers).*/

int *f_p(int *ptr)
{
  return ptr;
}

int *element_p2(int **ptr, int i)
{
  return ptr[i];
}

int main()
{
  int ret;
  int i = 0, j = 1, k = 2;
  int *p1 = &i, *p2 = &j, *p3 = &k;
  int array[10];
  int *a[4][3] = {p1,         p2+1,    ++p3,
                  array,      &j,      &k,
                  f_p(array), f_p(&j), f_p(p1)};
  int *ret_pi;

  ret_pi = element_p2((int**)a, 3);
  ret = *ret_pi;
  ret = *(ret_pi + 9);
  ret = ret_pi[10]; /*spatial error*/

  return 0;
}


