#include <string>
#include <vector>

class Faculty {
public:
	vector<Teacher> findTeachersBySubject(string subject);
	Student findStudentByFN(long fn);
	const Person& findPersonByEmail(string email);

	// load(string filename);
	// save(string filename);

	void add(Teacher teacher) {
		teachers.push_back(teacher);
	}
	void add(Student student) {
		students.push_back(student);
	}
private:
	// load(ifstream& in);
	// save(ofstream& out);

	string name;
	vector<Student> students;
	vector<Teacher> teachers;
};

vector<Teacher> Faculty::findTeachersBySubject(string subject) {
	vector<Teacher> result;
	for (int i = 0; i < teachers.size(); i++) {
		if (teachers[i].isTeachingSubject(subject)) {
			result.push_back(teachers[i]);
		}
	}
	return result;
}

Student Faculty::findStudentByFN(long fn) {
	for (int i = 0; i < students.size(); i++) {
		if (students[i].getFN() == fn) {
			return students[i];
		}
	}
	return Student("Not Found");
}

const Person& Faculty::findPersonByEmail(string email) {
	for (int i = 0; i < teachers.size(); i++) {
		if (teachers[i].getEmail() == email) {
			return teachers[i];
		}
	}

	for (int i = 0; i < students.size(); i++) {
		if (students[i].getEmail() == email) {
			return students[i];
		}
	}

	return Person("Not found");
}