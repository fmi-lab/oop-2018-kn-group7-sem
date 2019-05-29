#ifndef QUESTIONS_H_INCLUDED
#define	QUESTIONS_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Answer {
	Answer(string text, double points) {
		this->text = text;
		this->points = points;
	}

	string text;
	double points;
};


class TestParser {
public:
	TestParser(istream& in): in(in) {
	}

	string readQuestion() {
		string questionText;
		in.ignore();
		getline(in, questionText);
		return questionText;
	}

	Answer readAnswer() {
		double points;
		string answer;
		
		in >> points;
		getline(in, answer);

		return Answer(answer, points);
	}

	int readNumberOfAnswers() {
		int n; 
		in >> n;
		return n;
	}
private:
	istream& in;
};


class Question {
public:
	Question(string question);
	string getQuestion() const;

	virtual void print(ostream& out) const = 0;
	virtual double readAnswer(ostream& out, istream& in) const = 0;
	virtual void read(istream& in) = 0;
	virtual double getMaxPoints() const = 0;

	virtual ~Question();

protected:
	void setQuestion(string question);

private:
	string question;
};


class ShortAnswerQuestion : public Question {
public:
	ShortAnswerQuestion(string question="");
	ShortAnswerQuestion* setAnswer(string answer, double points);

	virtual void print(ostream& out) const;
	virtual double readAnswer(ostream& out, istream& in) const;
	virtual double getMaxPoints() const;
	virtual void read(istream& in);

private:
	string correntAnswer;
	double points;
};


class ChoicesQuestion : public Question {
public:
	ChoicesQuestion(string question="");
	ChoicesQuestion* addAnswer(string answer, double points = 0.0);

	virtual void print(ostream& out) const;
	virtual double getMaxPoints() const;
	virtual void read(istream& in);

protected:
	std::vector<Answer> answers;
};


class SingleChoiceQuestion : public ChoicesQuestion {
public:
	SingleChoiceQuestion(string question="");
	
	virtual void print(ostream& out) const;
	virtual double readAnswer(ostream & out, istream & in) const;	
};


class MultipleChoiceQuestion : public ChoicesQuestion {
public:
	MultipleChoiceQuestion(string question="");

	virtual void print(ostream& out) const;
	virtual double readAnswer(ostream & out, istream & in) const;
};

#endif