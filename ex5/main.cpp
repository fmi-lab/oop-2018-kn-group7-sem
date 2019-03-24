#include <iostream>
#include "student.h"
#include "university.h"

using namespace std;

int main() {
  Student student;
  student.read();

  University uni("SU");
  uni.add(student);
  uni.newStudents(10);
  uni.add(student);
  uni.print();
  uni.yearEnd();
  uni.print();
  return 0;
}
