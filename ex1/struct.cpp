#include <iostream>
#include <cstring>

using namespace std;

// Тип Данни
// struct
// количество памет, която събира няколко хетерогенни променливи
// != масива? // няколко неща vs едно нещо
// [0], [1] - индексен
// . поименен

// happiness score calculator
// "happy" -> 1.5
// "sad" -> -1.5
// ....

const char* words[] = { "happy", "sad" };
double score[] = { 1.5, -1.5 };

struct ScoredWord {
  char word[21];
  double score;
};
ScoredWord scoredWords[] = {
  { "happy", 1.5 },
  { "sad", -1.5 }
};

// Pass by value  vs  Pass by Reference
struct Person {
  char name[21];
  int age;

  // Default Constructor
  Person() {
    cout << "Default Constructor";
  }

  Person(const Person& person) {
    cout << "Copy Constructor";
  }

  // Person(Person&& person) {
  //   cout << "Move Constructor";
  // }

  // Constructor
  Person(const char * name, int age) {
    strcpy(this->name, name);
    this->age = age;
  }

  // Constructor
  Person(const char * aName, int birthYear, int month, int day) {
    strcpy(name, aName);
    age = 2019 - birthYear;
  }

  void read() {
    cout << "Name: ";
    cin >> this->name;
    cout << "Age: ";
    cin >> age;
  }

  void print() {
    cout << name << endl;
    cout << this->age << endl;
  }
};

void read(Person& p) {
  cout << "Name: ";
  cin >> p.name;
  cout << "Age: ";
  cin >> p.age; // works with the original variable
}

void read(Person* p) {
  cout << "Name: ";
  cin >> p->name;
  cout << "Age: ";
  cin >> (*p).age;
}

Person read() {
  Person p;
  cout << "Name: ";
  cin >> p.name;
  cout << "Age: ";
  cin >> p.age;
  return p; // creates a copy
}

Person createPerson(const char * name, int age) {
  Person p;
  strcpy(p.name, name);
  p.age = age;
  return p;
}

void print(Person p) {
  cout << p.name << endl;
  cout << p.age << endl;
}

// Example of constructor impl
// Person* createPerson(Person * this, const char * name, int age) {
//   this->name;
//   this->age;
//   return this;
// }

int main() {
  int x = 5;

  Person pesho = createPerson("Pesho", 100);
  // Person ivan = { "Ivan", 12 };
  Person mimi("Mimi", 5); // Person Person(Person* this, "Mimi", 5)
  Person lili("Lili", 1800, 1, 1);

  Person dragan;
  dragan.read();
  cout << "+++++++++++++++++++++++++++++" << endl;
  dragan.print();
  cout << "+++++++++++++++++++++++++++++" << endl;

  read(pesho);
  read(&pesho);
  Person ivan = read();

  cout << " =============================== " << endl;
  print(pesho);
  print(ivan);
  print(mimi);
  print(lili);

  for (int i = 0; i < 2; i++) {
    cout << scoredWords[i].word << ": " << scoredWords[i].score << endl;
  }

  return 0;
}
