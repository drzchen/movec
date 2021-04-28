/*Pointers (stack) pointing to
  constants (strings).*/

int main(int argc, char *argv[])
{
  char c;

  char *str = "a";

  c = *str;
  c = *(str+1);
  c = *(str+2); /*spatial error*/

  return 0;
}
