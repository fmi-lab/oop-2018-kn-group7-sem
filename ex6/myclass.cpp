#include <iostream>
using namespace std;

class MyClass {
public:
	MyClass() {
		x = 5;
		y = 6;
	}
	// a = b = c
	// a += b += c
	MyClass& operator=(const MyClass& other) {
		cout << "operator=(MyClass)" << endl;
		return *this;
	}

	int operator=(const char * text) {
		cout << "operator=" << text << endl;
		return strlen(text);
	}

	bool operator==(const MyClass& other) {
		return false;
	}

	int& operator[](int idx) {
		return y;
	}

	double operator[](double x) {
		return x * 0.42;
	}

	// Dictionary
	int operator[](const char * text) {
		cout << "operator[]" << text << endl;
		return strlen(text);
	}

	void operator++() {
		cout << "prefix operator++ " << endl;
	}

	void operator++(int ) {
		cout << "post operator++ " << endl;
	}
private:
	int x;
	int y;
};

int main() {
	MyClass m1;
	MyClass m2;

	m1 = m2;
	cout << (m1 = "ala bala nitsa") << endl;
	m1[6] += 10;
	m1[6] = 14;
	m1++;
	++m1;
	cout << m1[3.14] << endl;
	cout << m1["3.14 ... as text"] << endl;

	return 0;
}