#include <cstdio>

#define LINE puts("=============================================");
class Sample {
  int number;
public:
  Sample(int i) : number(i) {printf("Sample(%p,int)\n", this);};
  Sample() {printf("Sample(%p)\n", this);};
  ~Sample() {printf("~Sample(%p)\n", this);};

  void setNumber(int);
  int getNumber();
  int getNumber() const;
  void printNumber();

  Sample operator + (int);
  Sample operator + (const Sample&);
};

//This works in case the number comes first
Sample operator + (int, const Sample&);

int main () 
{
  puts("Entering main()");

  Sample a(3);
  Sample b(4);

  a.printNumber();
  b.printNumber();

  LINE
  (a + b).printNumber();
  LINE
  (a + 9).printNumber();
  LINE
  (b + 5).printNumber();
  LINE
  (a + b + a + b + 10).printNumber();
  LINE
  (a + b + 10 + a + b).printNumber();
  LINE
  (10 + a + b + a + b).printNumber();
  LINE

  puts("Exiting main()");
  return 0;
}

void Sample::setNumber(int i)
{
  this->number = i;
}

int Sample::getNumber()
{
  return this->number;
}

int Sample::getNumber() const
{
  return this->number;
}

void Sample::printNumber()
{
  printf("Instance: %p - Number: %d\n", this, this->number);
}

Sample Sample::operator + (int i)
{
  printf("Sample::operator + (%p, %d)\n", this, i);
  return Sample(this->number + i);
}

Sample Sample::operator + (const Sample& s)
{
  printf("Sample::operator + (%p, %p)\n", this, &s);
  return Sample(this->number + s.getNumber());
}

Sample operator + (int i, const Sample& s)
{
  printf("operator + (%d, %p)\n", i, &s);
  return Sample(i + s.getNumber());
}