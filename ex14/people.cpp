#ifndef PEOPLE_CPP
#define PEOPLE_CPP

#include <string>
#include <vector>

class Person {
public:
	Person(string name = "", string email = "") {
		this->name = name;
		this->email = email;
	}

	virtual string getName() const {
		return name;
	}

	virtual string getEmail() const {
		return email;
	}

	virtual Person* clone() const {
		return new Person(*this);
	}

	virtual void write(ostream& out) const {
		out << "person;" << name << ";" << email << endl;
	}

	virtual bool read(istream& in) {
		getline(in, name, ';');
		getline(in, email, ';');
		return true;
	}

private:
	string name;
	string email;
};

class Student : public Person {
public:
	Student(string name = "", string email = "", long fn = 0) :Person(name, email) {
		this->fn = fn;
	}

	long getFN() {
		return fn;
	}

	virtual Person* clone() const {
		return new Student(*this);
	}

	virtual void write(ostream& out) const {
		out << "student;" << getName() << ";" << getEmail() << ";" << fn << endl;
	}

	virtual bool read(istream& in) {
		if (Person::read(in)) {
			in >> fn;
			in.ignore();
			return true;			
		} else {
			return false;
		}
	}
private:
	long fn;
};

class Teacher : public Person {
public:
	Teacher(string name = "", string email = "", string subjects = "") :Person(name, email) {
		this->subjects = subjects;
	}

	string getSubjects() {
		return subjects;
	}

	bool isTeachingSubject(string subject) {
		return ("," + subjects + ",").find("," + subject + ",") != string::npos;
	}

	virtual Person* clone() const {
		return new Teacher(*this);
	}

	virtual void write(ostream& out) const {
		out << "student;" << getName() << ";" << getEmail() << ";" << subjects << endl;
	}

	virtual bool read(istream& in) {
		if (Person::read(in)) {
			getline(in, subjects);
			return true;			
		} else {
			return false;
		}
	}
private:
	string subjects;	
};

#endif