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
  ret = *p1;
  ret = p1[1];
  ret = p1[2]; /*spatial error*/

  return 0;
}
