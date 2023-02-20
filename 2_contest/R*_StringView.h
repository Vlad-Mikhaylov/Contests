#ifndef STRINGVIEW_H
#define STRINGVIEW_H
#include <stdexcept>

class StringViewOutOfRange : public std::out_of_range {
 public:
  StringViewOutOfRange() : std::out_of_range("StringViewOutOfRange") {
  }
};

class StringView {
 private:
  const char* string_;
  size_t length_;

 public:
  StringView();
  StringView(const char*);  // NOLINT
  StringView(const char*, size_t);
  const char& operator[](size_t) const;
  const char& At(size_t) const;
  const char& Front() const;
  const char& Back() const;
  size_t Size() const;
  size_t Length() const;
  bool Empty() const;
  const char* Data() const;
  void Swap(StringView&);
  void RemovePrefix(size_t);
  void RemoveSuffix(size_t);
  StringView Substr(size_t, size_t num = -1) const;
};

#endif