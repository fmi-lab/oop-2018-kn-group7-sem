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


class Question {
public:
	Question(string question);
	string getQuestion() const;

	virtual void print(ostream& out) const = 0;
	virtual double readAnswer(ostream& out, istream& in) const = 0;
	virtual double getMaxPoints() const = 0;

	virtual ~Question();

private:
	string question;
};


class ShortAnswerQuestion : public Question {
public:
	ShortAnswerQuestion(string question);
	ShortAnswerQuestion* setAnswer(string answer, double points);

	virtual void print(ostream& out) const;
	virtual double readAnswer(ostream& out, istream& in) const;
	virtual double getMaxPoints() const;

private:
	string correntAnswer;
	double points;
};


class ChoicesQuestion : public Question {
public:
	ChoicesQuestion(string question);
	ChoicesQuestion* addAnswer(string answer, double points = 0.0);

	virtual void print(ostream& out) const;
	virtual double getMaxPoints() const;

protected:
	std::vector<Answer> answers;
};


class SingleChoiceQuestion : public ChoicesQuestion {
public:
	SingleChoiceQuestion(string question);
	
	virtual void print(ostream& out) const;
	virtual double readAnswer(ostream & out, istream & in) const;
};


class MultipleChoiceQuestion : public ChoicesQuestion {
public:
	MultipleChoiceQuestion(string question);

	virtual void print(ostream& out) const;
	virtual double readAnswer(ostream & out, istream & in) const;
};

#endif