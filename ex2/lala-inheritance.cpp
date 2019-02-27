#include <iostream>
#include <cstring>

using namespace std;

void bala(void * xp) {
  cout << *((int*)xp) + 5 << endl;
}

void ala(void * xp) {
  bala(xp);
}

struct Person
{
  char name[21];
  int age;

  Person(const char * name, int age) {
    strcpy(this->name, name);
    this->age = age;
  }

  void print() {
    cout << name << " " << age << endl;
  }
};

struct Student  // will inherit Person
{
  char name[21];
  int age;
  int fn;

  Student(const char * name, int age, int fn) {
    strcpy(this->name, name);
    this->age = age;
    this->fn = fn;
  }

  void print() {
    cout << name << " " << age << " " << fn << endl;
  }
};

void setName(Person* person, const char * name) {
  strcpy(person->name, name);
}

void setAge(Person* person, int age) {
  person->age = age;
}

int main() {
  Person pesho("Peshoo", 12);
  Student mimi("Mimi", 21, 123);
  pesho.print();
  mimi.print();

  cout << ".................. " << endl;
  setName(&pesho, "Peter");
  setAge(&pesho, 13);

  setName((Person*)&mimi, "Mariika");
  setAge((Person*)&mimi, 22);

  pesho.print();
  mimi.print();

  return 0;
}
