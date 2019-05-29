#include "test.h"


// Static Factory, Static Factory Method
// Factory Method
Question* createQuestion(string questionType) {
	if (questionType == "single_choice") {
		return new SingleChoiceQuestion();
	} else if (questionType == "multiple_choice") {
		return new MultipleChoiceQuestion();
	} else if (questionType == "short_answer") {
		return new ShortAnswerQuestion();
	} else {
		cout << "Error: unknow question type" << endl;
		return NULL;
	}
}

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

void Test::loadFromFile(string filename) {
	ifstream in(filename);
	load(in);
	in.close();
}

void Test::load(istream & in) {
	while (!in.eof()) {
		string questionType;
		in >> questionType;

		Question * question = createQuestion(questionType);
		if (question != NULL) {
			question->read(in);
			add(question);
		}
	}
}

Test::~Test() {
	for (int i = 0; i < questions.size(); i++) {
		delete questions[i];
	}
}
