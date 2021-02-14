#include <cstdio>
#include <typeinfo>

int test1(int);
int test1(int, int);
void test1();
//int test1(); overload with different return types
// compiler cannot figerout which version to use now

class Sample 
{
public:
  int test2(int a)
  {
    return a;
  }

  int test2(int a, int b)
  {
    return a + b;
  }

  int test3(int a)
  {
    return ++a;
  }
};

int main()
{
  int a;
  char b;
  Sample s;
  printf("%s\n", typeid(double* []).name());

  if(typeid(a) != typeid(b))
  {
    puts("Yes, we're different!");
  }

  a = test1(1);
  a = test1(1,2);
  test1();
  //a = test1();

  printf("%d\n",a);

  printf("%d %d %d\n", s.test2(1), s.test2(1,2), s.test3(1));

  return 0;
}

int test1(int a)
{
  return ++a;
}

int test1(int a, int b)
{
  return a + b;
}

void test1() {}