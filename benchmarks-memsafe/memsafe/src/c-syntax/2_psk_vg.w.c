/*Pointers (stack) pointing to
  variables (global).*/

struct {
  int i;
  int j;
} st;

int main()
{
  int ret;

  int *p1;

  p1 = (int*)&st;
  p1[2] = ret; /*spatial error*/

  return 0;
}
