#include <cstdio>
#include "SampleClass.h"
#include <memory>
#include <typeinfo>
#include <execinfo.h>



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

int main()
{
  std::unique_ptr<SampleClassExt> pa_ext(new SampleClassExt(7));
  SampleClassExt b_ext = *pa_ext;
  SampleClassExt *pe_ext = &b_ext;
  BREAK_LINE
  auto pf_ext = std::make_unique<SampleClassExt>(5);

  b_ext.setNumber(6);
  (*pe_ext).setNumber(5);
  pa_ext->setNumber(95);
  BREAK_LINE
  pf_ext->setNumber(72);
#if 0

  PRINT("pa_ext type: %s\n", typeid(pa_ext).name());
  PRINT("b_ext type: %s\n", typeid(b_ext).name());
  PRINT("pe_ext type: %s\n", typeid(pe_ext).name());

  

  BREAK_LINE

  pa_ext->printNumber();
  pa_ext->setNumber(10);
  pa_ext->printNumber();

  BREAK_LINE

  auto pc_ext = std::move(pa_ext);
  PRINT("auto pc_ext = std::move(pa_ext)\n");
  PRINT("pc_ext type: %s\n", typeid(pc_ext).name());
  PRINT("pc_ext value: %d\n", pc_ext->getNumber());
  PRINT("pa_ext: %p, pc_ext: %p\n", pa_ext.get(), pc_ext.get());

  BREAK_LINE

  /*std::unique_ptr<SampleClassExt> pd_ext = std::move(pa_ext);
    this is an invalid action because pa_ext has been moved to pc_ext
  */
  std::unique_ptr<SampleClassExt> pd_ext = std::move(pc_ext);
  PRINT("std::unique_ptr<SampleClassExt> pd_ext = std::move(pc_ext)\n");
  PRINT("pd_ext type: %s\n", typeid(pd_ext).name());
  PRINT("pd_ext value: %d\n", pd_ext->getNumber());
#endif
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