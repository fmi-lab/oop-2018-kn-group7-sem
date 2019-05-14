#include <iostream>

using namespace std;

// abstract classes
class Question {
public:
	virtual double answer() {
		print();
		return readAnswer();
	}

protected:
	virtual void print() const = 0; // abstract methods
	virtual double readAnswer() const = 0;

private:
	char * question;
	double points;
};

class ShortAnswerQuestion : public Question {
protected:
	virtual void print() const {
		cout << "[Short Answer]: " << question << endl;
	}

	virtual double readAnswer() const {
		cout << "> ";
		char ans[1024];
		cin.getLine(ans, 1024);

		if (strcmp(correctAnswer, ans) == 0) {
			return points;
		} else {
			return 0;
		}
	}
private:
	char * correctAnswer;
};

struct ChoiceAnswer {
	char * answer;
	double points;
};

class ChoiceQuestion : public Question {
protected:
	virtual void print() const {
		cout << ": " << question << endl;
		for (int i = 0; i < numberOfAnswers; i++) {
			cout << (i + 1) << ". " << answers[i] << endl;
		}
	}

private:
	ChoiceAnswer * answers;
	int numberOfAnswers;
}

class SingleChoiceQuestion : public ChoiceQuestion {
protected:
	virtual void print() const {
		cout << "[Single Choice]";
		ChoiceQuestion::print();
	}
	
	virtual double readAnswer() const {
		cout << "> ";
		int ans;
		cin >> ans;
		ans--; // match to the array indexes

		if (ans != correctAnswer) {
			return 0;
		} else {
			return points;
		}
	}
};

class MultipleChoicesQuestion : public ChoiceQuestion {
protected:
	virtual void print() const {
		cout << "[Multiple Choice]";
		ChoiceQuestion::print();
	}
	
	virtual double readAnswer() const {
		cout << "Type 0 to stop giving answers" << endl;
		cout << "> ";
		
		double points = 0;
		int ans;
		cin >> ans;
		while (ans != 0) {
			ans--; // match to the array indexes
			points += answers[ans].points;

		}
		return poitns;
	}
};

class Test {
public:
	Test(int maxNumberOfQuestions) {
		this->maxNumberOfQuestions = maxNumberOfQuestions;
		this->questions = new Question*[maxNumberOfQuestions];
		this->numberOfQuestions = 0;
	}

	Test(const Test& other) {
		doCopy(other);
	}

	Test& operator=(const Test& other) {
		if (this != &other) {
			doDelete();
			doCopy(other);
		}
		return *this;
	}

	~Test() { 
		doDelete();
	}

	add(Question * question) {
		if (numberOfQuestions >= maxNumberOfQuestions) {
			extendQuestions();
		}

		questions[numberOfQuestions] = question;
		numberOfQuestions++;
	}

	void take() {
		double result = 0.0;
		for (int i = 0; i < numberOfQuestions; i++) {
			Question* currentQuestion = questions[i];
			result += currentQuestion->answer();
		}

		cout << "Your result is: " << result << endl;
	}
private:
	void doCopy(const Test& other) {
		this->maxNumberOfQuestions = other.maxNumberOfQuestions;
		this->numberOfQuestions = other.numberOfQuestions;
		this->questions = new Question*[other.maxNumberOfQuestions];
		for (int i = 0; i < this->numberOfQuestions; i++) {
			this->questions[i] = other.questions[i];
		}
	}

	void doDelete() {
		delete[] questions;
	}

	void extendQuestions() {
		// ... 
	}

private:
	Question ** questions;
	int numberOfQuestions;
	int maxNumberOfQuestions;
};


int main() {
	Test test(4);
	
	SingleChoiceQuestion* question1 = new SingleChoiceQuestion("Which of the bellow is NOT an access specifiers in C++?", 5);
	question1->addAnswer("Public");
	question1->addAnswer("Private");
	question1->addAnswer("Protected");
	question1->addAnswer("Package Default", true);
	test.add(question1);

	MultipleChoicesQuestion* question2 = new MultipleChoicesQuestion("Explain the features or concepts of Object-oriented programming (OOP)?", 10);
	question2->addAnswer("Objects", -1);
	question2->addAnswer("Abstraction", 0.25);
	question2->addAnswer("Encapsulation", 0.25);
	question2->addAnswer("Inheritance", 0.25);
	question2->addAnswer("Polymorphism", 0.25);
	question2->addAnswer("Classes", -1);
	question2->addAnswer("Programming",  -1);
	test.add(question2);

	ShortAnswerQuestion* question3 = new ShortAnswerQuestion("What's the name of the instance of a class", 5);
	question3->setAnswer("Object");
	test.add(question3);

	test.take();

	return 0;
}