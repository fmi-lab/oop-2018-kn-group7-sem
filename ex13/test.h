#ifndef TEST_H_INCLUDED
#define	TEST_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "questions.h"

using namespace std;

class Test {
public:	 
	void add(Question* q);
	void take(ostream & out, istream & in);
	~Test();
private:
	vector<Question*> questions;
};

#endif