#include <iostream>
using namespace std;

void str_copy(char*& target, const char * from) {
  target = new char[strlen(from) + 1]; // "ala" -> [a, l, a, \0]
  strcpy(target, from);
}

void str_delete(char * value) {
  if (value != NULL) {
    delete[] value;
  }
}

class Student {
public:
  Student() {
    name = NULL;
    fn = 0;
    specialty = NULL;
    year = 0;
    group = 0;
  }

  Student(const Student & other) {
    doCopy(other);
  }

  Student& operator=(const Student & other) {
    if (this != &other) {
      doDelete();
      doCopy(other);
    }
    return *this;
  }

  ~Student() {
    doDelete();
  }

  void read() {
    cout << "Name: ";
    str_delete(name);
    readString(name);
    cout << "Fn: ";
    cin >> fn;
    cout << "Specialty: ";
    str_delete(specialty);
    readString(specialty);
    cout << "Year: ";
    cin >> year;
    cout << "Group: ";
    cin >> group;
  }

  void print() const {
    cout << "========================================" << endl;
    cout << "Name: " << name << endl;
    cout << "Fn: " << fn << endl;
    cout << "Specialty: " << specialty << endl;
    cout << "Year: " << year << endl;
    cout << "Group: " << group << endl;
    cout << "========================================" << endl;
  }

  // static functions
  // Static Factory <-- Design Pattern
  // static Student readStudent() {
  // }

private:
  void readString(char*& target) {
    char buf[1000];
    cin.ignore();
    cin.getline(buf, 1000);
    str_copy(target, buf);
  }

  void doCopy(const Student & other) {
    str_copy(this->name, other.name);
    this->fn = other.fn;
    str_copy(this->specialty, other.specialty);
    this->year = other.year;
    this->group = other.group;
  }

  void doDelete() {
      str_delete(name);
      str_delete(specialty);
  }

private:
  char* name;
  int fn;
  char* specialty;
  int year;
  int group;
};

int main() {
  Student pesho;
  pesho.read();
  cout << "xxxxxxxxxxxxxxxxxxxxx" << endl;
  pesho.print();
  cout << "alaa bala" << endl;
  return 0;
}
