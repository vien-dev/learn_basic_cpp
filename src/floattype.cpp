#include <cstdio>

int main()
{
  float f;
  double df;
  long double ldf;

  printf("f:%ld, df:%ld, ldf:%ld\n", 
    sizeof(f), sizeof(df), sizeof(ldf));

  f = 34e37;

  printf("f:%f\n",f);

  return 0;
}