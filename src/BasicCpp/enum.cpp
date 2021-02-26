#include <cstdio>
#include <cstdint>

enum sample : uint16_t //uint8_t will give compilation error 
{
  A,
  B = 254,
  C,
  D,
  E,
  F
};


int main()
{
  
  printf("%d %d %d %d %d %d\n",
    A, B, C, D, E, F);
  return 0;
}