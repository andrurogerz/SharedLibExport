#include "FriendClass.hxx"

int FriendClass::doSomethingFriendly(FriendlyClass &obj) {
  return veryFriendlyFunction(obj);
}

int FriendlyClass::privateMethod() {
  return 8;
}

int veryFriendlyFunction(FriendlyClass &obj) {
  return obj.privateMethod() + 10;
}
