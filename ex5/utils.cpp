#ifndef UTILS_INCLUDED
#define UTILS_INCLUDED

#include <cstring>

void str_copy(char*& target, const char * from) {
  target = new char[strlen(from) + 1]; // "ala" -> [a, l, a, \0]
  strcpy(target, from);
}

void str_delete(char * value) {
  if (value != NULL) {
    delete[] value;
  }
}

#endif