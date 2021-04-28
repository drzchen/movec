/*Definitions of arrays (pointers and structures).*/

typedef struct st {
  int i;
  int *p;
} st;

int g_i = 0, g_j = 1, g_k = 2;
int g_array[10];

st g_obj[4][3] = {{{0, &g_i},         {1, &g_j+1},    {2, &g_k+1}},
                  {{3, g_array},      {4, &g_j},      {5, &g_k}},
                  {{6, g_array},      {7, &g_j},      {8, &g_k}} };

int main()
{
  int ret;

  ret = g_obj[1][0].p[9];
  ret = *g_obj[1][1].p;

  return 0;
}


