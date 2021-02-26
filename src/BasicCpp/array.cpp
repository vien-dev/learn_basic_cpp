#include <cstdio>

int main()
{
  int a[] = {1, 2, 3, 4, 5};
  int x=5;
  int b[x] = {1,2,3};
  for (int i : a) {
    printf("%d ", i);
  }
  puts("");
  for (int i : b) {
    printf("%d ", i);
  }
  puts("");
  x = 9+7;
  int c[x] = {};
  for (int i : c) {
    printf("%d ", i);
  }
  puts("");

  char s[] = "String";
  printf("%s\n",s);
  for (int i : s) {
    printf("%d ", i);
  }
  puts("");
  return 0;
}