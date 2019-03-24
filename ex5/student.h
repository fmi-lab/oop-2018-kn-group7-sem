#include <iostream>

#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

class Student {
public:
  Student();
  Student(const Student & other);
  Student& operator=(const Student & other);
  ~Student();

  int getYear() const;
  int getGroup() const;
  const char* getSpecialty() const;

  void moveToNextYear();
  void read();
  void print() const;

private:
  void readString(char*& target);
  void doCopy(const Student & other);
  void doDelete();

private:
  char* name;
  int fn;
  char* specialty;
  int year;
  int group;
};

#endif