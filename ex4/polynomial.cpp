#include <iostream>

using namespace std;

class Polynomial {
public:
  Polynomial(int power);
  ~Polynomial();
  Polynomial(const Polynomial& other);
  Polynomial& operator=(const Polynomial& other);

  Polynomial operator+(const Polynomial& other) const;
  Polynomial& operator+=(const Polynomial& other);

  void setCoefficient(int power, double coefficient);
  double getCoefficient(int power) const;

  void print() const;

private:
  void copy(const Polynomial& other);

private:
  int n;
  double * coefficients;
};

Polynomial::Polynomial(int power) {
  n = power;
  coefficients = new double[n+1];
  for (int i = 0; i <= n; i++) {
    coefficients[i] = 0;
  }
}

Polynomial::~Polynomial() {
  delete[] coefficients;
}

Polynomial::Polynomial(const Polynomial & other) {
  copy(other);
}

Polynomial& Polynomial::operator=(const Polynomial & other) {
  if (this != &other) {
    delete[] coefficients;
    copy(other);
  }
  return *this;
}

Polynomial Polynomial::operator+(const Polynomial & other) const {
  Polynomial result = *this;
  result+= other;
  return result;
}

Polynomial& Polynomial::operator+=(const Polynomial & other) {
  int n = max(this->n, other.n);
  double * coefficients = new double[n + 1];
  for (int i = 0; i <= n; i++) {
    coefficients[i] = this->getCoefficient(i) + other.getCoefficient(i);
  }

  delete[] this->coefficients;

  this->n = n;
  this->coefficients = coefficients;
  return *this;
}

void Polynomial::setCoefficient(int power, double coefficient) {
  if (0 <= power && power <= n) {
    coefficients[power] = coefficient;
  }
}

double Polynomial::getCoefficient(int power) const {
  if (power < 0 || power > n) {
    return 0;
  }

  return coefficients[power];
}

void Polynomial::copy(const Polynomial& other) {
  n = other.n;
  coefficients = new double[n + 1];
  for (int i = 0; i <= n; i++) {
    setCoefficient(i, other.getCoefficient(i));
  }
}

void Polynomial::print() const {
  bool isFirst = true;
  for (int i = n; i >= 0; i--) {
    double a = getCoefficient(i);
    if (a != 0) {
      if (!isFirst) {
        cout << " + ";
      }
      isFirst = false;

      if (i > 1) {
        if (a != 1) {
          cout << a;
        }
        cout << "x^" << i;
      } else if (i == 1) {
        if (a != 1) {
          cout << a;
        }
        cout << "x";
      } else if (i == 0) {
        cout << a;
      }
    }
  }
  cout << endl;
}

int main() {
  Polynomial p1(1); // x+1
  p1.setCoefficient(1, 1);
  p1.setCoefficient(0, 1);

  Polynomial p2(2); // x^2 + 3
  p2.setCoefficient(2, 1);
  p2.setCoefficient(0, 3);

  cout << endl << "p1, p2" << endl;
  p1.print();
  p2.print();

  cout << endl << "p1 += p2" << endl;
  p1 += p2;
  p1.print();
  p2.print();

  Polynomial p3 = p1 + p2;
  cout << endl << "p3 = p1 + p2" << endl;
  p1.print();
  p2.print();
  p3.print();

  return 0;
}
