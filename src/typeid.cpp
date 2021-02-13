#include <cstdio>
#include <typeinfo>

int main()
{
  int a;
  char b;
  printf("%s\n", typeid(double* []).name());

  if(typeid(a) != typeid(b))
  {
    puts("Yes, we're different!");
  }
  return 0;
}