#ifndef TEST_H_INCLUDED
#define	TEST_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "questions.h"

using namespace std;

class Test {
public:	 
	void add(Question* q);
	void take(ostream & out, istream & in);
	void loadFromFile(string filename);
	void load(istream & in);
	~Test();
private:
	vector<Question*> questions;
};

#endif