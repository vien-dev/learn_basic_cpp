#include <cstdio>
#include <memory>
#include "SampleClass.h"

void print_backtrace();

class SampleClassExt : public SampleClass {
public:
  SampleClassExt(int i) {
    this->setNumber(i);
    PRINT("SampleClassExt(%p, int)\n", this);
    print_backtrace();
  }

  SampleClassExt() {
    this->setNumber(0);
    PRINT("SampleClassExt(%p)\n", this);
    print_backtrace();
  }
  ~SampleClassExt() { PRINT("~SampleClassExt(%p)\n", this);}
  SampleClassExt(const SampleClassExt& rIns) {
    this->setNumber(rIns.getNumber());
    PRINT("SampleClassExt(%p, const SampleClassExt&)\n", this);
    print_backtrace();
  }
  SampleClassExt& operator= (const SampleClassExt& rIns) {
    this->setNumber(rIns.getNumber());
    PRINT("SampleClassExt& operator= (%p, const SampleClassExt&)\n", this);
    print_backtrace();
    return *this;
  }
  SampleClassExt& operator*() {
    PRINT("SampleClassExt& operator*(%p)\n", this);
    print_backtrace();
    return *this;
  }

  SampleClassExt& operator*(int) {
    PRINT("SampleClassExt& operator*(%p, int)\n", this);
    print_backtrace();
    return *this;
  }

  void printNumber();
  int getNumber();
  int getNumber() const;
};

void display_weak_ptr_content(std::weak_ptr<SampleClassExt> wp) {
  PRINT("Weak_ptr count before locking: %ld\n",wp.use_count());
  if (auto spt = wp.lock()) {
    PRINT("Weak_ptr count after locking: %ld\n",wp.use_count());
    spt->printNumber();
  }
  else {
    PRINT("weak ptr is expired! Shared ptr doesnt manage any object\n");
  }
}

int main() {
  auto a = std::make_shared<SampleClassExt>(9);
  std::weak_ptr<SampleClassExt> b = a;
  PRINT("shared pointer a count: %ld\n", a.use_count());
  display_weak_ptr_content(b);
  auto a1 = a;
  auto a2 = a;
  auto a3 = a;
  PRINT("shared pointer a count: %ld\n", a.use_count());
  display_weak_ptr_content(b);
  PRINT("a3: %d\n", a3->getNumber());
  PRINT("a2->setNumber(5);\n");
  a2->setNumber(5);
  PRINT("a1: %d\n", a3->getNumber());
  display_weak_ptr_content(b);

  a1.reset();
  a2.reset();
  a3.reset();
  a.reset();

  PRINT("shared pointer a count: %ld\n", a.use_count());
  display_weak_ptr_content(b);
  {
    auto c = std::make_shared<SampleClassExt>(16);
    b = c;

    display_weak_ptr_content(b);
  }
  display_weak_ptr_content(b);

  SampleClassExt* pd = new SampleClassExt(17);
  std::shared_ptr<SampleClassExt> d(pd);
  PRINT("shared pointer d count: %ld\n", d.use_count());

  b = d;
  display_weak_ptr_content(b);

  //delete pd; -> this will cause problem because shared ptr doesn't smart enough to realize the dealloc of its managed objects outside its scope.
  //PRINT("shared pointer d count: %ld\n", d.use_count());
  //display_weak_ptr_content(b);

  return 0;
}

void SampleClassExt::printNumber() {
    PRINT("void SampleClassExt::printNumber(%p): %d\n", this,
      this->getNumber());
    print_backtrace();
}

int SampleClassExt::getNumber() {
  PRINT("int SampleClassExt::getNumber(%p)\n", this);
  print_backtrace();
  return SampleClass::getNumber();
}

int SampleClassExt::getNumber() const {
  PRINT("int SampleClassExt::getNumber(%p) const\n", this);
  print_backtrace();
  return SampleClass::getNumber();
}


void print_backtrace()
{
#if 0
  //implementation copied from https://man7.org/linux/man-pages/man3/backtrace.3.html
#define BT_BUF_SIZE 100

  int nptrs;
  void *buffer[BT_BUF_SIZE];
  char **strings;

  nptrs = backtrace(buffer, BT_BUF_SIZE);
  PRINT("backtrace() returned %d addresses\n", nptrs);

  /* The call backtrace_symbols_fd(buffer, nptrs, STDOUT_FILENO)
    would produce similar output to the following: */

  strings = backtrace_symbols(buffer, nptrs);
  if (strings == NULL) {
      perror("backtrace_symbols");
      exit(EXIT_FAILURE);
  }

  for (int j = 0; j < nptrs; j++)
      PRINT("%s\n", strings[j]);

  free(strings);

  puts("");

#undef BT_BUF_SIZE
#endif
}
