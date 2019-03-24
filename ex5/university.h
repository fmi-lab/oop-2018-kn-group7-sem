#include <iostream>
#include "student.h"

#ifndef UNIVERSITY_H_INCLUDED
#define UNIVERSITY_H_INCLUDED

class University {
public:
	University(const char * name);
	University(const University& other);
	University& operator=(const University& other);
	~University();

	void newStudents(int n);
	void add(Student& student);
	void yearEnd();

	int getNumberOfStudents() const;
	int getNumberOfStudents(int year) const;
	int getNumberOfStudents(int year, const char * specialty) const;

	void print() const;

private:
	void doCopy(const University& other);
	void doDelete();

private:
	char * name;
	Student * students;
	int numberOfStudents;
	int maxStudents;
};

#endif