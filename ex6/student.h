#ifndef STUDENT_H_DEFINED
#define STUDENT_H_DEFINED

class Student {
public:
	Student();
	~Student();
	Student(const Student& other);
	Student& operator=(const Student& other);
private:
	char * name;
};

#endif