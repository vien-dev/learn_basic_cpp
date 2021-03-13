#include <cstdio>
#include <utility>

#define BREAK_LINE puts("===============================");

#define MK_STR(cmd) #cmd
#define DO(cmd) puts(MK_STR(cmd));cmd;

class SampleClassExt {
  int theNumber;
  int *theNumberPointer;
public:
  void setNumber(int);
  int getNumber();
  int getNumberFromPtr();
  void printNumber();

  SampleClassExt();
  SampleClassExt(int);
  SampleClassExt operator+(const SampleClassExt&) const;

  //rule of five
  SampleClassExt(const SampleClassExt &);
  SampleClassExt(SampleClassExt&&) noexcept;
  SampleClassExt& operator=(const SampleClassExt &);
  SampleClassExt& operator=(SampleClassExt &&) noexcept;
  ~SampleClassExt();
};
int main() {
  DO(SampleClassExt a = 5);
  DO(SampleClassExt b = a);
  BREAK_LINE

  DO(a.printNumber())
  DO(b.printNumber())

  BREAK_LINE

  DO(SampleClassExt c)
  DO(c.printNumber())
  DO(c = std::move(b))
  DO(b.printNumber())
  DO(c.printNumber())

  BREAK_LINE

  DO(SampleClassExt d = b + c)
  DO(d.printNumber())

  BREAK_LINE

  DO(a = b + c)

  DO(a.printNumber())

  BREAK_LINE

  DO(SampleClassExt e = a + b + c + d)
  DO(e.printNumber())

  BREAK_LINE

  DO(SampleClassExt f = std::move(a + b))
  DO(f.printNumber())

  BREAK_LINE
  return 0;
}

void SampleClassExt::setNumber(int number) {
  this->theNumber = number;
  *(this->theNumberPointer) = number; 
}

int SampleClassExt::getNumber() {
  return this->theNumber;
}

int SampleClassExt::getNumberFromPtr() {
  return *(this->theNumberPointer);
}

void SampleClassExt::printNumber() {
  printf("%p has number: %d\n", this, this->theNumber);
  
  printf("%p has number ptr (%p) points to memory area with value: %d\n", this, this->theNumberPointer, *(this->theNumberPointer));
}

SampleClassExt::SampleClassExt() {
  printf("SampleClassExt::SampleClassExt(%p)\n", this);
  this->theNumber = 0;
  this->theNumberPointer = new int;
  *(this->theNumberPointer) = 0;
}
SampleClassExt::SampleClassExt(int i) {
  printf("SampleClassExt::SampleClassExt(%p, %d)\n", this, i);
  this->theNumber = i;
  this->theNumberPointer = new int;
  *(this->theNumberPointer) = i;
}
SampleClassExt SampleClassExt::operator+(const SampleClassExt& rIns) const {
  printf("SampleClassExt SampleClassExt::operator+(%p, %p)\n", this, &rIns);
  return SampleClassExt(this->theNumber + rIns.theNumber);
}
SampleClassExt::SampleClassExt(const SampleClassExt & rIns) {
  printf("SampleClassExt::SampleClassExt(%p, &%p)\n", this, &rIns);
  this->theNumber = rIns.theNumber;
  this->theNumberPointer = new int;
  *(this->theNumberPointer) = *(rIns.theNumberPointer);
}
SampleClassExt::SampleClassExt(SampleClassExt&& rIns) noexcept {
  printf("SampleClassExt::SampleClassExt(%p, &&%p)\n", this, &rIns);
  this->theNumber = rIns.theNumber;
  this->theNumberPointer = rIns.theNumberPointer;
  rIns.theNumberPointer = nullptr;
}
SampleClassExt& SampleClassExt::operator=(const SampleClassExt &rIns) {
  printf("SampleClassExt& SampleClassExt::operator=(%p, &%p)\n", this, &rIns);
  this->theNumber = rIns.theNumber;
  *(this->theNumberPointer) = *(rIns.theNumberPointer);
  return *this;
}
SampleClassExt& SampleClassExt::operator=(SampleClassExt &&rIns) noexcept {
  printf("SampleClassExt& SampleClassExt::operator=(%p, &&%p)\n", this, &rIns);
  this->theNumber = rIns.theNumber;
  std::swap(this->theNumberPointer, rIns.theNumberPointer);
  return *this;
}
SampleClassExt::~SampleClassExt() {
  printf("SampleClassExt::~SampleClassExt(%p)\n", this);
  printf("Before dealloc memory for theNumberPointer(%p)\n", this->theNumberPointer);
  delete this->theNumberPointer;
  printf("After dealloc memory for theNumberPointer(%p)\n", this->theNumberPointer);
}
