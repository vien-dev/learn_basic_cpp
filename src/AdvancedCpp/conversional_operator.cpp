#include <cstdio>
#include "SampleClass.h"
#include <string>

class SampleClassExt : public SampleClass {
public:
  operator std::string() const;
  operator int() const;
};

int main()
{
  SampleClassExt a;

  a.setNumber(5);
  //need conversional operator to support this conversion to string
  printf("a.getNumber() c_str:%s, int:%d\n", 
      std::string(a).c_str(), int(a)); 
  
  int b = 0;

  b = 6 + a;

  printf("b = 6 + a = %d\n", b);


  return 0;
}

SampleClassExt::operator std::string() const {
  return std::to_string(this->getNumber());
}

SampleClassExt::operator int() const {
  return this->getNumber();
}
