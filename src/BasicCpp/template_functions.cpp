#include <cstdio>

class Sample
{
  int number;
public:
  Sample() : number(0) {};
  Sample(int i) : number(i) {};
  ~Sample() {};

  void setNumber(int);
  int getNumber() const;
  void printNumber();
  Sample operator + (const Sample&) const;
};

template <typename T>
T sumOf(T a, T b)
{
  return a + b;
};

int main()
{
  Sample a;
  Sample b(5);

  a.setNumber(9);

  a.printNumber();
  b.printNumber();

  printf("sumOf<Sample>(a, b) = %d\n", sumOf<Sample>(a, b).getNumber());
  printf("sumOf<int>(9, 5) = %d\n", sumOf<int>(a.getNumber(), b.getNumber()));

  return 0;
}

void Sample::setNumber(int i)
{
  this->number = i;
}

int Sample::getNumber() const
{
  return this->number;
}

void Sample::printNumber()
{
  printf("Instance: %p - number: %d\n", this, this->number);
}

Sample Sample::operator + (const Sample& s) const
{
  return Sample(this->number + s.getNumber());
}