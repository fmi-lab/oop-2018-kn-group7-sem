#include "test.h"


void Test::add(Question* q) {
	questions.push_back(q);
}

void Test::take(ostream & out, istream & in) {
	double maxPoints = 0;
	double result = 0;

	// questions.getNumberOfQuestions()
	for (int i = 0; i < questions.size(); i++) {
		// https://en.wikipedia.org/wiki/Law_of_Demeter


		// questions.getQuestion(i);
		maxPoints += questions[i]->getMaxPoints();
		questions[i]->print(out); // ostream
		result += questions[i]->readAnswer(out, in); // istream
	}

	out << "Your result is " << result << "/" << maxPoints << endl;
}

Test::~Test() {
	for (int i = 0; i < questions.size(); i++) {
		delete questions[i];
	}
}
