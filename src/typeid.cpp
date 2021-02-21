#include <cstdio>
#include <typeinfo>

int test1(int);
int test1(int, char);
void test1();
//int test1(); overload with different return types
// compiler cannot figerout which version to use now

struct sample_struct {
  int a;
  int b;
};

class Sample 
{
  int number;
public:
  Sample(int i) : number(i)
  {
    puts("Sample(int)");
  }

  void setNum( int i )
  {
    this->number = i;
  }

  int getNum()
  {
    puts("get num with non-const Sample");
    return this->number;
  }

  int getNum() const
  {
    puts("get num with const Sample");
    return this->number;
  }

  int test2(int a)
  {
    return a;
  }

  int test2(int a, int b)
  {
    puts("test 2 with non-const this");
    return ++number + a + b;
  }

  int test2(int a, int b) const
  {
    puts("test 2 with const this");
    return number + a + b;
  }

  int test3(int a)
  {
    return ++a;
  }

  int test3()
  {
    return number;
  }

  int test3 (sample_struct s)
  {
    return ++number + s.a + s.b;
  }

  Sample & operator = (const Sample & rightSample)
  {
    puts("Assign operator is invoked");
    this->number = rightSample.number;
    return *this;
  }

  Sample operator + (const Sample & rightSample) const
  {
    puts("+ operator is invoked");
    return Sample(this->number + rightSample.getNum());
  }
};

int main()
{
  int a;
  long long int b = 2500;
  Sample s(3);
  Sample s2 = s;
  printf("%s\n", typeid(double* []).name());

  if(typeid(a) != typeid(b))
  {
    puts("Yes, we're different!");
  }

  a = test1(1);
  a = test1(1,b);
  test1();
  //a = test1();

  printf("%d\n",a);

  printf("%d %d %d %d\n", s.test2(1), s.test2(1,2), s.test3(1), s.test3());

  printf("%d\n", s2.test3());

  s.setNum(6);

  printf("%d\n", (s2 = s).test3());

  printf("%d\n", (s + s2).getNum());

  return 0;
}

int test1(int a)
{
  return ++a;
}

int test1(int a, char b)
{
  return a + b;
}

void test1() {}