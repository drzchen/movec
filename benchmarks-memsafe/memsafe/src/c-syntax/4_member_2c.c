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
  stn sn1 = {s1, s2};

  ret = ((st*)&sn1)->i;
  ret = ((st*)&sn1+1)->i;
  ret = ((st*)&sn1+2)->i; /*spatial error*/

  return 0;
}

