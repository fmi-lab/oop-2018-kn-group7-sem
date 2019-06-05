#include <fstream>

class Faculty {
public:
	Faculty(string name = "") {
		this->name = name;
	}

	vector<Teacher> findTeachersBySubject(string subject);
	Student findStudentByFN(long fn);
	const Person& findPersonByEmail(string email);

	void add(const Person* person) {
		people.push_back(person->clone());	// deep copy | clone
	}

	void load(string filename) {
		ifstream in(filename);
		load(in);
		in.close();
	}

	void save(string filename) {
		ofstream out(filename);
		save(out);
		out.close();
	}

private:
	// Person File Parser
	Person* createPerson(string personType) {
		if (personType == "student") {
			return new Student();
		} else if (personType == "teacher") {
			return new Teacher();
		} else {
			return NULL;
		}
	}

	void load(istream& in) {
		getline(in, name);
		while (!in.eof()) { // EOF == End of File
			string personType;
			getline(in, personType, ';');
			
			Person* person = createPerson(personType);
			if (person == NULL) {
				continue;
			}
			if (person->read(in)) {
				people.push_back(person);
			}

		}
	}

	void save(ofstream& out) {
		out << name << endl;
		for (int i = 0; i < people.size(); i++) {
			people[i]->write(out);
		}
	}

private:
	string name;
	vector<Person*> people;
};

vector<Teacher> Faculty::findTeachersBySubject(string subject) {
	vector<Teacher> result;
	for (int i = 0; i < people.size(); i++) {
		// DOWN cast
		if(Teacher* teacher = dynamic_cast<Teacher*>(people[i])) {
			if (teacher->isTeachingSubject(subject)) {
				result.push_back(*teacher);
			}
		}
	}
	return result;
}

Student Faculty::findStudentByFN(long fn) {
	for (int i = 0; i < people.size(); i++) {
		if (Student * student = dynamic_cast<Student*>(people[i])) {
			if (student->getFN() == fn) {
				return *student;	
			}
		}
	}
	return Student("Not Found");
}

const Person& Faculty::findPersonByEmail(string email) {
	for (int i = 0; i < people.size(); i++) {
		if (people[i]->getEmail() == email) {
			return *people[i];
		}
	}
	return Person("Not Found");
}