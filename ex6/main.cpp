#include <iostream>

#include "test.cpp"
#include "test.cpp"

#include "student.h"
#include "faculty.h"

using namespace std;

// Pre-Processor
// #include 
#define ALA_BALA 10
#define ALA(x) for (int i = 0; i < x; i++) 

int main (){
	cout << "ALA_BALA" << endl;
	ALA(5) {
		cout << i << "/" << 5 << " my ala" << endl;
	}

	#ifndef ALABALA_DEFINED
	#define ALABALA_DEFINED
	cout << "FROM ALABALA_DEFINED" << endl;
	#endif

	#ifndef ALABALA_DEFINED
	#define ALABALA_DEFINED
	cout << "FROM ALABALA_DEFINED" << endl;
	#endif

	Faculty faculty;
	Student pesho;

	return 0;
}
