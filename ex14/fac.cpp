#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <fstream>

#include "people.cpp"
// #include "faculty.cpp"
#include "faculty_with_person.cpp"

int main() {
	Faculty fmi("FMI");
	Student s1("pesho Petrov", "pesho@fmi.com", 123456);
	fmi.add(&s1);

	Student s2("ivan Petrov", "ivan@fmi.com", 2020202);
	fmi.add(&s2);
	
	Student s3("dragan Petrov", "dragan@fmi.com", 3030303);
	fmi.add(&s3);

	Teacher t1("mimi Petrova", "mimi@teacher.fmi.com", "up,oop,sdp");
	fmi.add(&t1);
	Teacher t2("lili Petrova", "lili@teacher.fmi.com", "oop");
	fmi.add(&t2);
	Teacher t3("pepi Petrova", "pepi@teacher.fmi.com", "ai");
	fmi.add(&t3);

	cout << fmi.findPersonByEmail("pepi@teacher.fmi.com").getName() << endl;
	cout << fmi.findPersonByEmail("ivan@fmi.com").getName() << endl;
	cout << fmi.findTeachersBySubject("oop")[0].getName() << endl;
	cout << fmi.findTeachersBySubject("oop")[1].getName() << endl;
	cout << fmi.findStudentByFN(2020202).getName() << endl;

	fmi.save("output.txt");

	cout << "==================================" << endl;

	Faculty newFMI;
	newFMI.load("input.txt");
	cout << newFMI.findPersonByEmail("pepi@teacher.fmi.com").getName() << endl;
	cout << newFMI.findPersonByEmail("ivan@fmi.com").getName() << endl;
	cout << newFMI.findTeachersBySubject("oop")[0].getName() << endl;
	cout << newFMI.findTeachersBySubject("oop")[1].getName() << endl;
	cout << newFMI.findStudentByFN(2020202).getName() << endl;

	return 0;
}