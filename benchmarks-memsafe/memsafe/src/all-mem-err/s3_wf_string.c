/*Wrapper functions in string.h.*/
#include <string.h>
#include <stdlib.h>

int main()
{
  char *str1 = "sky2098";
  char *str2 = (char*)malloc(sizeof(char) * 10);
  str2[0] = '\0';

  str2 = strcat(str2, "abc");
  str2 = strcat(str2, str1); /*str2 spatial error*/

  free(str2);

  return 0;
}
