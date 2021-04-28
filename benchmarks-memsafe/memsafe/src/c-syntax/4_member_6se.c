/*Member expressions.*/

typedef struct st {
  int i;
  int j;
  struct st *next;
} st;

/*nested structure type*/
typedef struct stn {
  st st1;
  st st2;
} stn;

int main()
{
  int ret;
  st s2 = {2, 3, &s2-1};
  st s1 = {0, 1, &s2};
  int i = 0;

  st *sp1 = &s1;

  ret = (i++==0?sp1:++sp1)->i;
  ret = (++i==1?sp1:sp1++)->i;
  ret = (++i==3?sp1:sp1++)->i; /*spatial error*/

  return 0;
}

