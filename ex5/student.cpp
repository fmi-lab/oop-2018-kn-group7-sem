#include <iostream>
#include "student.h"
#include "utils.h"
using namespace std;

Student::Student() {
  name = NULL;
  fn = 0;
  specialty = NULL;
  year = 0;
  group = 0;
}

Student::Student(const Student & other) {
  doCopy(other);
}

Student& Student::operator=(const Student & other) {
  if (this != &other) {
    doDelete();
    doCopy(other);
  }
  return *this;
}

Student::~Student() {
  doDelete();
}

int Student::getYear() const {
  return year;
}

int Student::getGroup() const {
  return group;
}

const char* Student::getSpecialty() const {
  return specialty;
}


void Student::read() {
  cout << "Name: ";
  str_delete(name);
  readString(name);
  cout << "Fn: ";
  cin >> fn;
  cout << "Specialty: ";
  str_delete(specialty);
  cin.ignore();
  readString(specialty);
  cout << "Year: ";
  cin >> year;
  cout << "Group: ";
  cin >> group;
}

void Student::moveToNextYear() {
  year++;
}

void Student::print() const {
  cout << "========================================" << endl;
  cout << "Name: " << name << endl;
  cout << "Fn: " << fn << endl;
  cout << "Specialty: " << specialty << endl;
  cout << "Year: " << year << endl;
  cout << "Group: " << group << endl;
  cout << "========================================" << endl;
}

void Student::readString(char*& target) {
  char buf[1000];
  cin.getline(buf, 1000);
  str_copy(target, buf);
}

void Student::doCopy(const Student & other) {
  str_copy(this->name, other.name);
  this->fn = other.fn;
  str_copy(this->specialty, other.specialty);
  this->year = other.year;
  this->group = other.group;
}

void Student::doDelete() {
    str_delete(name);
    str_delete(specialty);
}
