#include <cstdio>

class Sample {
public:
  int static_value1() {
    static int x = 7;
    x++;

    return x;
  }
  int static_value2() {
    static int x = 47;
    x++;

    return x;
  }
};

int main()
{
  Sample s1;
  Sample s2;
  Sample s3;

  printf("%d %d\n", s1.static_value1(), s1.static_value2());
  printf("%d %d\n", s2.static_value1(), s2.static_value2());
  printf("%d %d\n", s3.static_value1(), s3.static_value2());
  return 0;
}