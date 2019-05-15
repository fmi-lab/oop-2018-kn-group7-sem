#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct X {
	int a;
	double b;
};

void readFromBinary() {
	ifstream in("out.txt", ios_base::binary);
	int a;
	X x;
	
	in.read((char*)&a, sizeof(a));
	in.read((char*)&x, sizeof(x));

	cout << "A: " << a << endl;
	cout << "x.a: " << x.a << endl;
	cout << "x.b: " << x.b << endl;

	in.close();
}

void writeToBinary() {
	ofstream output("out.txt", ios_base::binary); // open file, CREATE file descriptor
	int a = 101;
	X x = {2, 3.2};

	output.write((const char*)&a, sizeof(a));
	output.write((const char*)&x, sizeof(x));

	output << "1. ala bala nitsa" << endl;
	output << "2. ala bala nitsa" << endl;
	output << "3. ala bala nitsa" << endl;
	output << "4. ala bala nitsa" << endl;
	output.close(); // !!!!!!!!
}

void writeToText() {
	ofstream output("out.txt", ios_base::binary); // open file, CREATE file descriptor
	output << "1. ala bala nitsa" << endl;
	output << "2. ala bala nitsa" << endl;
	output << "3. ala bala nitsa" << endl;
	output << "4. ala bala nitsa" << endl;
	output.close(); // !!!!!!!!
}

void readFromText() {
	ifstream in("out.txt");
	int x;
	in >> x;
	cout << "x: " << x << endl;

	string str;
	getline(in, str, ',');
	getline(in, str, ',');
	cout << "str: " << str << endl;

	double a;
	in >> a;
	cout << "a: " << a << endl;

	in.close();	
}

int main() {
	return 0;
}
