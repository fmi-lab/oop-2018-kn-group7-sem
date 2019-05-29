#include "questions.h"


// Question
///////////////////////////////////////////////////////////
Question::Question(string question) {
	this->question = question;
}

string Question::getQuestion() const {
	return question;
}

Question::~Question() {

}


// ShortAnswerQuestion
///////////////////////////////////////////////////////////
ShortAnswerQuestion::ShortAnswerQuestion(string question) : Question(question) {
}

ShortAnswerQuestion* ShortAnswerQuestion::setAnswer(string answer, double points) {
	this->correntAnswer = answer;
	this->points = points;
	return this;
}

void ShortAnswerQuestion::print(ostream& out) const {
	out << "[Short Answer] " << getQuestion() << ":" << endl;
}

double ShortAnswerQuestion::readAnswer(ostream& out, istream& in) const {
	out << "> ";
	string ans;
	in.ignore();
	getline(in, ans);
	return ans == correntAnswer ? points : 0;
}

double ShortAnswerQuestion::getMaxPoints() const {
	return points;
}


// ChoicesQuestion
///////////////////////////////////////////////////////////
ChoicesQuestion::ChoicesQuestion(string question) : Question(question) {

}

ChoicesQuestion* ChoicesQuestion::addAnswer(string answer, double points) {
	answers.push_back(Answer(answer, points));
	return this;
}

void ChoicesQuestion::print(ostream& out) const {
	out << getQuestion() << ":" << endl;
	for (int i = 0; i < answers.size(); i++) {
		out << (i+1) << ") " << answers[i].text << endl;
	}
	out << endl;
}

double ChoicesQuestion::getMaxPoints() const {
	double maxPoints = 0;
	for (int i = 0; i < answers.size(); i++) {
		maxPoints += answers[i].points;
	}
	return maxPoints;
}


// SingleChoiceQuestion
///////////////////////////////////////////////////////////
SingleChoiceQuestion::SingleChoiceQuestion(string question) : ChoicesQuestion(question) {
}

void SingleChoiceQuestion::print(ostream& out) const {
	out << "[Single Choice Question] ";
	ChoicesQuestion::print(out);
}

double SingleChoiceQuestion::readAnswer(ostream & out, istream & in) const {
	out << "> ";
	int ans;
	in >> ans;
	
	ans -= 1;
	if (0 <= ans && ans < answers.size()) {
		return answers[ans].points;
	}
	return 0;
}


// MultipleChoiceQuestion
///////////////////////////////////////////////////////////
MultipleChoiceQuestion::MultipleChoiceQuestion(string question) : ChoicesQuestion(question) {
}

void MultipleChoiceQuestion::print(ostream& out) const {
	out << "[Multiple Choice Question] ";
	ChoicesQuestion::print(out);
}

double MultipleChoiceQuestion::readAnswer(ostream & out, istream & in) const {	
	double points = 0;

	out << "Type 0 to stop adding answers" << endl;
	while (true) {
		out << "> ";
		int ans;

		in >> ans;
		if (ans <= 0) {
			return points;
		}
		ans -= 1;
		if (ans < answers.size()) {
			if (answers[ans].points > 0) {
				points += answers[ans].points;
			} else {
				points = 0; // Wrong answer
			}
		}
	}
	
	return points;
}