#include <cstdio>
#include <typeinfo>

class SampleClass
{
  int theNumber;
  SampleClass() {puts("Invoking SampleClass()");};
public:
  SampleClass(int i) : theNumber(i) {puts("Invoking SampleClass(int)");};
  ~SampleClass() {puts("Invoking ~SampleClass()");};
  void setNumber(int i) { this->theNumber = i; }
  int getNumber() { return this->theNumber; }
  int getNumber() const { return this->theNumber; }
};

class SampleClassExt : public SampleClass {
public:
  SampleClassExt();
  SampleClassExt(int);
  ~SampleClassExt();
};

int main()
{
  SampleClassExt* a_ext = new SampleClassExt;
  SampleClassExt* b_ext = new SampleClassExt(5);
  delete a_ext;
  delete b_ext;
  return 0;
}

SampleClassExt::SampleClassExt() : SampleClass(0) {
  printf("Invoking %s() for class %s\n", __func__, typeid(this).name());
}

SampleClassExt::SampleClassExt(int i) : SampleClass(i) {
  printf("Invoking %s(int) for class %s\n", __func__, typeid(this).name());
}

SampleClassExt::~SampleClassExt() {
  printf("Invoking %s() for class %s\n", __func__, typeid(this).name());
}
