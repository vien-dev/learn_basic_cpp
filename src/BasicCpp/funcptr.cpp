#include <cstdio>

void sample1();
void sample2();

int main()
{
  void (*func_ptr[2])()= {nullptr};

  func_ptr[0] = &sample1;

  func_ptr[0]();

  func_ptr[1] = sample2;

  func_ptr[1]();

  return 0;
}

void sample1()
{
  puts("Sample 1");
}

void sample2()
{
  puts("Sample 2");
}