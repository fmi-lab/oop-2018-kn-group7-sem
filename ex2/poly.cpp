#include <iostream>

// Pre Processor
// #

#define ALABALA for (int i = 0; i < n; i++)

using namespace std;

// conventions

// ### public
// Interface of a class = all public methods (== function), constructors, fields

// public Constructors
// public methods
// public fields
// private Constructors
// private methods
// private fields

// ### private
// State = all fields

// private fields
// private Constructors
// private methods
// public fields
// public Constructors
// public methods




template <typename T>
class Poly {
public:
  Poly(int n, T a[]) {
    this->n = n;
    for (int i = 0 ; i < n; i++){
      this->a[i] = a[i];
    }
  }

  void print() {

  }

private:
  int n;
  T a[100];
};

// struct Poly  { };

// Poly* Poly_____Poly(Poly * this, int n, T a[]) {

//   return this;
// }

// void Poly_____print(Poly * this, int n, T a[]) {
// }

int main() {
  // Poly p(5, ...);

  // Poly p; //as a structure
  // Poly_____Poly(&p, 5, ...);

  int n = 50;
  ALABALA
    cout << "1" << endl;

  return 0;
}
