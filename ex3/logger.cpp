#include <iostream>

using namespace std;

void coutMessage(const char * str) {
  cout << str << endl;
}

void coutMessage(const char * str, int a, int b) {
  cout << str << "; a= " << a << "; b= " << b << endl;
}

void skipMessage(const char * str) {
}

void skipMessage(const char * str, int a, int b) {
}

// ERROR
// WARNING
// INFO
// DEBUG

// Multiline edit/selection

// struct vs class
//

class Logger {
public:
  void (*error) (const char *);
  void (*warning) (const char *);
  void (*info) (const char *, int, int);
  void (*debug) (const char *, int, int);

  Logger() {
    cout << "### Default Constructor" << endl;

    error = coutMessage;
    warning = coutMessage;
    info = coutMessage;
    debug = coutMessage;
  }

  Logger(const Logger& other) {
    cout << "### Copy-Constructor" << endl;

    error = other.error;
    warning = other.warning;
    info = other.info;
    debug = other.debug;
  }

  Logger& operator=(const Logger& other) {
    cout << "### Operator= " << endl;

    if (this != &other) {
      error = other.error;
      warning = other.warning;
      info = other.info;
      debug = other.debug;
    }
    return *this;
  }

  ~Logger() {
    cout << "### Destructor " << endl;

    error = NULL;
    warning = NULL;
    info = NULL;
    debug = NULL;
  }

};

Logger productionLogger() {
  Logger logger;
  logger.error = coutMessage;
  logger.warning = skipMessage;
  logger.info = skipMessage;
  logger.debug = skipMessage;
  return logger;
}

Logger debugLogger() {
  Logger logger;
  return logger;
}


void sort(int a[], int n, bool (*shouldSwap)(int, int), Logger logger)  {
  if (n == 0) {
    logger.warning("The array is empty");
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      logger.debug("before swap", a[i], a[j]);
      if (shouldSwap(a[i], a[j])) {
        logger.debug("inside swap", a[i], a[j]);
        swap(a[i], a[j]);
        logger.info("did swap", a[i], a[j]);
      }
    }
  }
  logger.error("blah blah blah");
}

bool asc(int a, int b) {
  return a > b;
}

bool desc(int a, int b) {
  return a < b;
}

int main() {
  int a[] = {1, 2, 33, 4, 5};
  int n = 5;

  Logger myLogger0;
  cout << "myLogger0 ====================================" << endl;

  Logger myLogger1(myLogger0);
  cout << "myLogger1 ====================================" << endl;

  Logger myLogger2;
  myLogger2 = productionLogger();
  cout << "myLogger2 ====================================" << endl;

  sort(a, n, asc, productionLogger());
  cout << " ======================================================== " << endl;
  sort(a, n, desc, debugLogger());

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}
