#include <iostream>

using namespace std;

class Person {
public:
	Person(const char * name, long dateOfBirth) {
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
		this->dateOfBirth = dateOfBirth;
	}

	~Person() {
		doDelete();
	}

	Person(const Person & other) {
		doCopy(other);
	}

	Person& operator=(const Person & other) {
		if (this != &other) {
			doDelete();
			doCopy(other);
		}
		return *this;
	}

	const char * getName() const {
		return name;
	}

	long getDateOfBirth() const {
		return dateOfBirth;
	}

	virtual void print() const;
protected:
	void setName(const char * name) {
		delete this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}

	void setDateOfBirth(int dateOfBirth) {
		this->dateOfBirth = dateOfBirth;
	}

private:
	void doDelete() {
		delete[] name;
	}
	void doCopy(const Person & other) {
		this->name = new char[strlen(other.name) + 1];
		strcpy(this->name, other.name);
		this->dateOfBirth = other.dateOfBirth;
	}
private:
	char* name;
	long dateOfBirth;
};

void Person::print() const {
	cout << "Name: " << name << "; DOB: " << dateOfBirth << endl;
}

class Student : public Person {
public:
	Student(int fn): Person("Unknown", 19991011) {
		this->fn = fn;
	}

	virtual void print() const {
		// Person::print();
		cout << "Name: " << getName() 
			 << "; DOB: " << getDateOfBirth()
			 << "; FN: " << fn 
			 << endl;
	}

	int getFN() const {
		return fn;
	}
private:
	int fn;
};

struct S1 {
	int a;
	int b;
};

struct S2 {
	int a;
	int b;
	int c;
};

int main() {
	S1 s1;
	s1.a = 5;
	s1.b = 10;

	S2 s2;
	s2.a = 15;
	s2.b = 20;
	s2.c = 30;

	S1 * p = &s1;
	cout << p->a << endl;
	cout << p->b << endl;

	p = (S1*) &s2;
	cout << p->a << endl;
	cout << p->b << endl;
	cout << ((S2*)p)->c << endl;

	Person pesho = Person("Pesho", 19901011);
	pesho.print();

	Student ivan = Student(11111);
	ivan.print();
	ivan.print();

	// Polymorphism
	cout << "_____________Polymorphism_______________" << endl;
	Person * pp = &pesho;
	pp->print();
	pp = &ivan;
	pp->print();

	cout << endl << endl << endl << endl;
	Student * ps = &ivan;
	ps->print();




	return 0;
}