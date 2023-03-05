#ifndef CPPSTRING_H
#define CPPSTRING_H
#include <stdexcept>
#include <sstream>
class StringOutOfRange : public std::out_of_range {
 public:
  StringOutOfRange() : std::out_of_range("StringOutOfRange") {
  }
};

// YOUR CODE...
class String {
 public:
  char* string_;
  size_t size_;
  size_t capacity_;
  String();
  String(size_t, char);
  String(const char*);  // NOLINT
  String(const char*, size_t);
  String(const String&);
  String& operator=(const String&);
  ~String();
  const char& operator[](size_t) const;
  char& operator[](size_t);
  char& At(size_t);
  const char& At(size_t) const;
  char& Front();
  const char& Front() const;
  char& Back();
  const char& Back() const;
  char* CStr();
  const char* CStr() const;
  char* Data();
  const char* Data() const;
  bool Empty();
  bool Empty() const;
  size_t Size();
  size_t Size() const;
  size_t Length();
  size_t Length() const;
  size_t Capacity();
  size_t Capacity() const;
  void Clear();
  void Swap(String&);
  void PopBack();
  void PushBack(char);
  String& operator+=(const String&);
  void Resize(size_t, char);
  void Reserve(size_t);
  void Reserve();
  void ShrinkToFit();
};
String operator+(const String&, const String&);
bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);
bool operator<(const String&, const String&);
bool operator>(const String&, const String&);
bool operator<=(const String&, const String&);
bool operator>=(const String&, const String&);
std::istream& operator>>(std::istream&, String);
std::ostream& operator<<(std::ostream&, String);
#endif