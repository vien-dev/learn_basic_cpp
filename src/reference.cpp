#include <cstdio>

int main()
{
  int x = 5;
  const int &y = x;
  int z = y;

  printf("x: %d, y: %d, z: %d\n", x, y, z);

  z = 3;

  printf("x: %d, y: %d, z: %d\n", x, y, z);

  // y = 6; cannot do this because y is now a read-only reference.

  printf("x: %d, y: %d, z: %d\n", x, y, z);

  return 0;
}