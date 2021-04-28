/*Sub-object overflow in stack.*/

typedef struct
{
  int m1;
  int m2;
} st;

int main()
{
  st s;
  int *p = &s.m1;
  p[1] = 0; /* spatial error */
  return 0;
}
