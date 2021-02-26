#include <cstdio>

const char string[] = "This is a null-terminated string.";
int main()
{
  /*int count = 0;

  for(const char* cp=string; *cp; cp++)
  {
    count++;
  }
  */
  int count = 0;
  for (count = 0; string[count]; count++);

  printf("The number of characters is %d\n", count);

  return 0;
}