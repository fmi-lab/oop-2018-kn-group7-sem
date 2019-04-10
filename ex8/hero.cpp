#include <iostream>

using namespace std;

// 				Hero
// DC  vs Marvel
// Deadpool, Wolverine, Magnito,
//

class Hero {
public:
	Hero () {

	}
	Hero(char * name, char * realName) {

	}
	virtual void useSuperPower() {
		cout << "....";
	};

	const char * getName() const {
		return name;
	}

protected:
	const char * getRealName() const {
		return realName;
	}

private:
	char * name;
	char * realName;
};

class DCHero : public Hero {
public:
	virtual void useSuperPower() {
		cout << "DC ... " << endl;
	}
};

class Batman : public DCHero {
public:
	virtual void useSuperPower() {
		DCHero::useSuperPower();
		cout << "I'm rich!!!" << endl;
	}
};

class MarvelHero : public Hero {
public:
	virtual void useSuperPower() {
		cout << "Marvel ... " << endl;
	}
};

class Deadpool : public MarvelHero {
public:
	virtual void useSuperPower() {
		MarvelHero::useSuperPower();
		cout << "8th March" << endl;
	}
};

class Wolverine : public MarvelHero {
public:
	virtual void useSuperPower() {
		MarvelHero::useSuperPower();
		cout << "Fast regen..." << endl;
	}
};
class Magnito : public MarvelHero {
public:
	virtual void useSuperPower() {
		MarvelHero::useSuperPower();
		cout << "Metal baby ... " << endl;
	}
};

int main() {
	Hero * heroes[4] = {
		new Magnito(), 
		new Wolverine(), 
		new Batman(), 
		new Deadpool()
	};

	for (int i = 0; i < 4; i++) {
		heroes[i]->useSuperPower();
	}

	for (int i = 0; i < 4; i++) {
		delete heroes[i];
	}
	return 0;
}
