#include <cstdio>
#include <cstdint>

int main()
{
  char i1;
  short int i2;
  int i3;
  long int i4;
  long long int i5;

  printf("c:%ld, si:%ld, i:%ld, li:%ld, lli:%ld\n", sizeof(i1), sizeof(i2), sizeof(i3), sizeof(i4), sizeof(i5));
  printf("ui8:%ld, ui16:%ld, ui32:%ld, ui64:%ld\n", sizeof(uint8_t), sizeof(uint16_t), sizeof(uint32_t), sizeof(uint64_t));
  printf("i8:%ld, i16:%ld, i32:%ld, i64:%ld\n", sizeof(int8_t), sizeof(int16_t), sizeof(int32_t), sizeof(int64_t));
  return 0;
}