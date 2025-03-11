#include "Annotations.h"

class SDK_ABI ExportedSimpleClass {
public:
  ExportedSimpleClass();
  virtual ~ExportedSimpleClass();

  int get() const {
    return value_;
  }

  SDK_ABI friend int exportedSimpleClassGetAndSet(ExportedSimpleClass &obj, int value);

  virtual void set(int);
  virtual const char* identify() const;

  static char ID[];

private:
  void setInternal(int);

private:
  int value_;
};

SDK_ABI int exportedSimpleClassGetAndSet(ExportedSimpleClass &obj, int value);
