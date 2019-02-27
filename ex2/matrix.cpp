#include <iostream>

using namespace std;

// 4. Събиране на матрици
// 5. Умножение на матрици

template <typename T>
void sum(T a[][100], T b[][100], T result[][100], int n, int m) {

}

template <typename T, int N, int M>
void sum(T a[N][M], T b[N][M], T result[N][M]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      result[i][j] = a[i][j] + b[i][j];
    }
  }
}


template <typename T, int N, int K, int M>
void product(T a[N][K], T b[K][M], T result[N][M], T nullValue = 0) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      T sum = nullValue;
      for (int k = 0; k < K; k++) {
        sum += a[i][k] * b[k][j];
      }
      result[i][j] = sum;
    }
  }
}

template <typename T, int N, int M>
void print(T a[N][M]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int a[2][2] = { {1, 2}, {3, 4} };
  int b[2][2] = { {10, 20}, {30, 40} };
  int c[2][2];

  sum<int, 2, 2>(a, b, c);
  print<int, 2, 2>(c);

  product<int, 2, 2, 2>(a, b, c, 10000);
  print<int, 2, 2>(c);

  int x1[3][2] = { {1, 2}, {3, 4}, {5, 6} };
  int x2[2][1] = { {10}, {100} };
  int x3[3][1];

  product<int, 3, 2, 1>(x1, x2, x3);
  print<int, 3, 1>(x3);

  return 0;
}








