#include <iostream>

using namespace std;

void addElement(int a[], int n, int * lastElement) {
  if (*lastElement < n) {
    cout << "Input new element: ";
    cin >> a[*lastElement];
    (*lastElement)++;
  }
}

void sort(int a[], int n, bool isAsc) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (isAsc && a[i] < a[j]) {
        swap(a[i], a[j]);
      } else if (!isAsc && a[j] < a[i]) {
        swap(a[i], a[j]);
      }
    }
  }
}

void sortAsc(int a[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] < a[j]) {
        swap(a[i], a[j]);
      }
    }
  }
}

void sortDesc(int a[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] > a[j]) {
        swap(a[i], a[j]);
      }
    }
  }
}

// function pointer
void sort(int a[], int n, bool (*shouldSwap)(int, int))  {
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (shouldSwap(a[i], a[j])) {
        swap(a[i], a[j]);
      }
    }
  }
}

bool asc(int a, int b) {
  return a > b;
}

bool desc(int a, int b) {
  return a < b;
}

int main() {
  int a[100];
  int na = 100;
  int lastElementA = 0;
  addElement(a, na, &lastElementA);
  addElement(a, na, &lastElementA);
  addElement(a, na, &lastElementA);
  addElement(a, na, &lastElementA);
  addElement(a, na, &lastElementA);

  int b[50];
  int nb = 50;
  int lastElementB = 0;
  addElement(b, nb, &lastElementB);

  bool (*sortOrder)(int, int);
  sortOrder = asc;

  cout << "Sort desc? ";
  char ans;
  cin >> ans;
  if (ans == 'y') {
    sortOrder = desc;
  }

  for (int i = 0; i < lastElementA; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}
