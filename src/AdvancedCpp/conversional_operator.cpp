#include <cstdio>
#include "SampleClass.h"
#include <string>
#include <typeinfo>
#include <iostream>

#define BREAK_LINE puts("==============================================");

class SampleClassExt : public SampleClass {
public:
  operator std::string() const;
  operator int() const;
};

class SampleClassExt2 : public SampleClass {
public:
  SampleClassExt2() = default;
  SampleClassExt2(int i) {this->setNumber(i);};
  SampleClassExt2 operator+(const SampleClassExt2&) const;
  void printNumber() const;
};

class SampleClassExt3 : public SampleClassExt {
  int theNumber2;
public:
  SampleClassExt3() = default;
  // The rule of 3
  SampleClassExt3(const SampleClassExt3 & rIns) {this->setNumber(rIns.getNumber());};
  SampleClassExt3 operator= (int i) {
    puts("invoking overload= (int) operator for SampleClassExt3");
    this->setNumber(i); return *this;
  };
  SampleClassExt3 operator= (const SampleClassExt3 & rIns) {
    puts("invoking overload= (const SampleClassExt3&) operator for SampleClassExt3");
    this->setNumber(rIns.getNumber()); return *this;
  }
  ~SampleClassExt3() = default;
};

int main()
{
  SampleClassExt a_ext;

  a_ext.setNumber(5);
  //need conversional operator to support this conversion to string and int
  printf("a_ext.getNumber() c_str:%s, int:%d\n", 
      std::string(a_ext).c_str(), int(a_ext)); 

  BREAK_LINE

  int b_int = 0;

  b_int = 6 + a_ext;

  printf("b_int = 6 + a_ext = %d\n", b_int);

  BREAK_LINE

  SampleClassExt b_ext;

  b_ext.setNumber(9);

//In the Ext class, a_ext and b_ext are converted to int before plus
  printf("a_ext + b_ext = %d\n", int(a_ext + b_ext));

  BREAK_LINE

  SampleClassExt2 a_ext2, b_ext2, c_ext2;

  a_ext2.setNumber(12);
  b_ext2.setNumber(43);

//In the Ext2 class, since + operator is overloaded
//plus between objects of Ext2 class occurs directly
//operator= is the default one
  c_ext2 = a_ext2 + b_ext2;

  c_ext2.printNumber();
  printf("c_ext2 = a_ext2 + b_ext2 = %d\n", c_ext2.getNumber());

  BREAK_LINE

  SampleClass a_base;

  a_base = a_ext2 + b_ext2;

  printf("a_base = a_ext2 + b_ext2 = %d\n", a_base.getNumber());

  BREAK_LINE

  SampleClassExt3 a_ext3, b_ext3, c_ext3, d_ext3;
  a_ext3.setNumber(4);
  b_ext3.setNumber(9);

  printf("c_ext3: %p, d_ext3: %p\n", &c_ext3, &d_ext3);
  d_ext3 = (d_ext3 = c_ext3 = a_ext3 + b_ext3) + d_ext3;
  printf("c_ext3: %p, d_ext3: %p\n", &c_ext3, &d_ext3);

  printf("c_ext3 = a_ext3 + b_ext3 = %d\n", c_ext3.getNumber());
  printf("d_ext3 = %d\n", d_ext3.getNumber());

  BREAK_LINE

  std::string a_str = "The value is: ";
  a_base.setNumber(5);
  a_ext.setNumber(6);
  a_ext2.setNumber(7);
  a_ext3.setNumber(8);

  //std::cout << a_str + std::string(a_base) << std::endl; failed because there's no conversional operator
  std::cout << a_str + std::string(a_ext) << std::endl;
  //std::cout << a_str << int(a_ext2) << std::endl; compilation failed because there's no conversional operator
  std::cout << a_str + std::string(a_ext3) << std::endl;

  return 0;
}

SampleClassExt::operator std::string() const {
  puts("invoking string type conversional operator for SampleClassExt");
  return std::to_string(this->getNumber());
}

SampleClassExt::operator int() const {
  puts("invoking int type conversional operator for SampleClassExt");
  return this->getNumber();
}

SampleClassExt2 SampleClassExt2::operator+ (const SampleClassExt2& rIns) const {
  printf("invoking overload + operator for %s\n", typeid(this).name());
  return SampleClassExt2(this->getNumber() + rIns.getNumber());
}

void SampleClassExt2::printNumber() const {
  printf("[%p] has theNumber as: %d\n", this, this->getNumber());
}