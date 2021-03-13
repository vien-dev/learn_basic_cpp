#if !defined(NO_LOG)
#define BREAK_LINE puts("===================================");

#define PRINT(format,...) printf(format, ##__VA_ARGS__ );
#else
#define BREAK_LINE
#define PRINT(format, ...)
#endif

class SampleClass
{
  int theNumber;
public:
  SampleClass() {PRINT("Invoking SampleClass()\n");};
  virtual void setNumber(int i) { this->theNumber = i; }
  virtual int getNumber() { return this->theNumber; }
  virtual int getNumber() const { return this->theNumber; }
};