#include <iostream>

using namespace std;


class MyClass {
public:
  MyClass();
  void read();
  void print() const;
private:
  int x;
};

MyClass::MyClass() {
  x = 0;
}

void MyClass::read() {
  cout << "x = ";
  cin >> x;
}

void MyClass::print() const {
  cout << "x = " << x << endl;
}


int main() {
  MyClass m;
  m.print();
  m.read();
  m.print();
  return 0;
}
