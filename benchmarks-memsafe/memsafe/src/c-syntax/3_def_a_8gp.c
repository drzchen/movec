/*Definitions of arrays (global pointer values).*/

int g_i = 0, g_j = 1, g_k = 2;
int g_array[10];
int *g_a[4][3] = {&g_i,         &g_j+1,    &g_k+1,
                  g_array,      &g_j,      &g_k,
                  g_array,      &g_j,      &g_k};

int main()
{
  int ret;

  ret = g_a[1][0][9];
  ret = g_a[1][0][10]; /*spatial error*/

  return 0;
}


