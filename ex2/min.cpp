#include <iostream>
#include <cstring>

using namespace std;

// 1. Min за 2 елементи
// 2. Min за 3 елементи
// 3. Min за масив

template <typename T>
T mymin(T a, T b) {
  return a < b ? a : b;
}

double mymin(double a, double b) {
  cout << "Blah blah double" << endl;
  return a < b ? a : b;
}

template <typename T, typename U>
void print(T a, U b) {
  cout << a << " ( " << b << " )" << endl;
}

template <typename T>
T mymin(T a, T b, T c) {
  return mymin(a, mymin(b, c));
}

template <typename T>
T mymin(T arr[], int n) {
  if (n <= 0) {
    T x;
    return x;
  }

  if (n == 1) {
    return arr[0];
  }

  T currentMin = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] < currentMin) {
      currentMin = arr[i];
    }
  }
  return currentMin;
}

template <int N, typename T>
T mymin(T arr[]) {
  if (N <= 0) {
    T x;
    return x;
  }

  if (N == 1) {
    return arr[0];
  }

  T currentMin = arr[0];
  for (int i = 1; i < N; i++) {
    if (arr[i] < currentMin) {
      currentMin = arr[i];
    }
  }
  return currentMin;
}

// int mymin_____int(int a, int b) {
//   return a < b ? a : b;
// }


// int mymin_____int(int a, int b, int c) {
//   return mymin_____int(a, mymin_____int(b, c));
// }

// Var args ???
int main() {

  int a = 5;
  long b = 6;
  double d1 = 5.5;
  double d2 = 7.5;

  cout << mymin(1, 2) << endl;
  cout << mymin<long>(a, b) << endl;
  cout << mymin('e', 'd') << endl;
  cout << mymin(d1, d2) << endl;

  cout << "mymin(10, 5, 3): " << mymin(10, 5, 3) << endl;
  cout << "mymin('d', 'c', 'e'): " << mymin('d', 'c', 'e') << endl;

  print(5, 6);
  print("Pesho", 6);

  int ai[5] = {10,2,3,4,5};
  char ac[6] = {'8','2','3','4','5', '0'};

  cout << "min(ai): " << mymin(ai, 5) << endl;
  cout << "min(ac): " << mymin(ac, 6) << endl;

  cout << "min(ai): " << mymin<5>(ai) << endl;
  cout << "min(ac): " << mymin<6>(ac) << endl;

  return 0;
}
