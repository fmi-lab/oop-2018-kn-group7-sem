#include <iostream>
#include <string>
#include <vector>
#include "test.h"

using namespace std;

int main() {
	Test mytest;

	mytest.add(
		(new SingleChoiceQuestion("Choose the invalid predefined macro as per ANSI C."))
		->addAnswer("__FILE__")
		->addAnswer("__DATE__")
		->addAnswer("__TIME__")
		->addAnswer("__C++__", 5)
	);

	mytest.add(
		(new MultipleChoiceQuestion("What the 4 principles of OOP?"))
		->addAnswer("Encapsulation", 2.5)
		->addAnswer("Inheritance", 2.5)
		->addAnswer("Abstraction", 2.5)
		->addAnswer("Polymorphism", 2.5)
		->addAnswer("Functional programming")
	);

	mytest.add(
		(new ShortAnswerQuestion("How to print \\n on the screen ?"))
		->setAnswer("\\n", 5)
	);

	mytest.add(
		(new SingleChoiceQuestion("A single line comment in C language source code can begin with _____"))
		->addAnswer(";")
		->addAnswer("//", 2)
		->addAnswer(":")
		->addAnswer("/*")
	);

	mytest.add(
		(new MultipleChoiceQuestion("How to print new line in C++"))
		->addAnswer("endl", 2.5)
		->addAnswer("\\n", 2.5)
		->addAnswer("newline")
		->addAnswer("endline")
	);

	mytest.add(
		(new ShortAnswerQuestion("Stderr is a standard error."))
		->setAnswer("Yes", 5)
	);

	mytest.take(cout, cin);

	return 0;
}