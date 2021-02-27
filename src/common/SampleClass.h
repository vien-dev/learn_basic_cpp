class SampleClass
{
  int theNumber;
public:
  void setNumber(int i) { this->theNumber = i; }
  int getNumber() { return this->theNumber; }
  int getNumber() const { return this->theNumber; }
};