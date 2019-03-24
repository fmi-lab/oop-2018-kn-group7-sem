#include <iostream>
#include <cstring>
#include "student.h"
#include "university.h"
#include "utils.h"

using namespace std;

University::University(const char * name) {
	numberOfStudents = 0;
	maxStudents = 0;
	students = new Student[0];
	str_copy(this->name, name);
}

University::University(const University& other) {
	doCopy(other);
}

University& University::operator=(const University& other) {
	if (this != &other) {
		doDelete();
		doCopy(other);
	}
	return *this;
}

University::~University() {
	doDelete();
}

void University::newStudents(int n) {
	Student * newStudents = new Student[maxStudents + n];
	for (int i = 0; i < numberOfStudents; i++) {
		newStudents[i] = students[i];
	}
	delete[] students;
	students = newStudents;
	maxStudents = maxStudents + n;
}

void University::add(Student& student) {
	if (numberOfStudents < maxStudents) {
		students[numberOfStudents++] = student;
	}
}

void University::yearEnd() {
	int studentsLeft = numberOfStudents - getNumberOfStudents(4);
	Student * newStudents = new Student[studentsLeft];
	int newStudentsIdx = 0;
	for (int i = 0; i < numberOfStudents; i++) {
		if (students[i].getYear() < 4) {
			newStudents[newStudentsIdx] = students[i];	
			newStudents[newStudentsIdx].moveToNextYear();
			newStudentsIdx++;
		}
	}
	delete[] students;
	students = newStudents;
	maxStudents = studentsLeft;
	numberOfStudents = studentsLeft;
}

int University::getNumberOfStudents() const {
	return numberOfStudents;
}

int University::getNumberOfStudents(int year) const {
	int count = 0;
	for (int i = 0; i < numberOfStudents; i++) {
		if (students[i].getYear() == year) {
			count++;
		}
	}
	return count;
}

int University::getNumberOfStudents(int year, const char * specialty) const {
	int count = 0;
	for (int i = 0; i < numberOfStudents; i++) {
		if (students[i].getYear() == year && strcmp(students[i].getSpecialty(), specialty) == 0) {
			count++;
		}
	}
	return count;
}

void University::print() const {
	cout << name << endl;
	for (int i = 0; i < numberOfStudents; i++) {
		students[i].print();
	}
}

void University::doCopy(const University& other) {
	this->numberOfStudents = other.numberOfStudents;
	this->maxStudents = other.maxStudents;
	this->students = new Student[this->maxStudents];
	for (int i = 0; i < other.numberOfStudents; i++) {
		this->students[i] = other.students[i];
	}
	str_copy(this->name, other.name);
}

void University::doDelete() {
	delete[] name;
	delete[] students;
}