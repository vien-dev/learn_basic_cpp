#include <cstdio>

struct sample {
  int a;
  double b;
  const char* c;
};

int main()
{
  sample s = {1,2,"hello"};

  printf("Sample: %d, %f, %s\n", s.a, s.b, s.c);
  
  return 0;
}