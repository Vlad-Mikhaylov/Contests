#include <iostream>
#include "cstring.h"

size_t Strlen(const char* str) {
  size_t count = 0;
  while (str[count] != '\0') {
    count++;
  }
  return count;
}
int Strcmp(const char* first, const char* second) {
  size_t len_first = Strlen(first);
  size_t len_second = Strlen(second);
  for (size_t i = 0; i < (len_first < len_second ? len_second : len_first); i++) {
    if (static_cast<int>(first[i]) < static_cast<int>(second[i])) {
      return -1;
    }
    if (static_cast<int>(first[i]) > static_cast<int>(second[i])) {
      return 1;
    }
  }
  return 0;
}
int Strncmp(const char* first, const char* second, size_t count) {
  for (size_t i = 0; i < count; i++) {
    if ((first[i] == '\0') & (second[i] == '\0')) {
      return 0;
    }
    if (static_cast<int>(first[i]) < static_cast<int>(second[i])) {
      return -1;
    }
    if (static_cast<int>(first[i]) > static_cast<int>(second[i])) {
      return 1;
    }
  }
  return 0;
}
char* Strcpy(char* dest, const char* src) {
  size_t len = Strlen(src);
  for (size_t i = 0; i < len + 1; i++) {
    dest[i] = src[i];
  }
  return dest;
}

char* Strncpy(char* dest, const char* src, size_t count) {
  size_t len = Strlen(src);
  for (size_t i = 0; i < count; i++) {
    dest[i] = (i >= len ? '\0' : src[i]);
  }
  return dest;
}
char* Strcat(char* dest, const char* src) {
  size_t len = Strlen(dest);
  size_t endl = Strlen(src);
  for (size_t i = len; i < len + endl; i++) {
    dest[i] = src[i - len];
  }
  return dest;
}
char* Strncat(char* dest, const char* src, size_t count) {
  size_t len = Strlen(dest);
  size_t endl = Strlen(src);
  if (count >= endl) {
    return Strcat(dest, src);
  }
  for (size_t i = len; i < len + count; i++) {
    dest[i] = src[i - len];
  }
  dest[len + count] = '\0';
  return dest;
}
const char* Strchr(const char* str, char symbol) {
  size_t len = Strlen(str);
  for (size_t i = 0; i < len + 1; i++) {
    if (str[i] == symbol) {
      return (str + i);
    }
  }
  return nullptr;
}
const char* Strrchr(const char* str, char symbol) {
  size_t len = Strlen(str);
  int position = -1;
  for (size_t i = 0; i < len + 1; i++) {
    if (str[i] == symbol) {
      position = i;
    }
  }
  if (position > -1) {
    return (str + position);
  }
  return nullptr;
}
size_t Strspn(const char* dest, const char* src) {
  size_t len = Strlen(src);
  size_t endl = Strlen(dest);
  size_t counter = 0;
  for (size_t j = 0; j < endl; j++) {
    for (size_t i = 0; i < len; i++) {
      if (src[i] == dest[j]) {
        counter++;
      }
    }
    if (counter == 0) {
      return j;
    }
    counter = 0;
  }
  return endl;
}

size_t Strcspn(const char* dest, const char* src) {
  size_t len = Strlen(src);
  size_t endl = Strlen(dest);
  size_t counter = 0;
  for (size_t j = 0; j < endl; j++) {
    for (size_t i = 0; i < len; i++) {
      if (src[i] == dest[j]) {
        counter++;
      }
    }
    if (counter != 0) {
      return j;
    }
    counter = 0;
  }
  return endl;
}

const char* Strpbrk(const char* dest, const char* breakset) {
  size_t len = Strlen(breakset);
  size_t endl = Strlen(dest);
  for (size_t i = 0; i < len; i++) {
    for (size_t j = 0; j < endl; j++) {
      if (breakset[i] == dest[j]) {
        return dest + j;
      }
    }
  }
  return nullptr;
}
const char* Strstr(const char* str, const char* pattern) {
  size_t len = Strlen(str);
  size_t endl = Strlen(pattern);
  size_t point;
  size_t j = 0;
  if ((endl == 0) & (len == 0)) {
    return str;
  }
  if (endl == 0) {
    return str;
  }
  for (size_t i = 0; i < len; i++) {
    while (true) {
      if ((i + j < len) & (str[i + j] == pattern[j])) {
        if (j == 0) {
          point = i;
        }
        if (j == endl - 1) {
          return str + point;
        }
        j++;
      } else {
        break;
      }
    }
    j = 0;
  }
  return nullptr;
}