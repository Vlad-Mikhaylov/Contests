#include "cppstring.h"
#include <iostream>
String::String() {
  this->string_ = nullptr;
  this->size_ = 0;
  this->capacity_ = 0;
}
String::String(size_t size, char symbol) {
  if (size != 0) {
    this->string_ = new char[size];
    this->size_ = size;
    this->capacity_ = size;
    for (size_t i = 0; i < size; i++) {
      this->string_[i] = symbol;
    }
  } else {
    this->string_ = nullptr;
    this->size_ = 0;
    this->capacity_ = 0;
  }
}
String::String(const char* other) {  // NOLINT
  if (other != nullptr) {
    size_t i = 0;
    while (other[i] != '\0') {
      i++;
    }
    this->size_ = i;
    this->capacity_ = i;
    if (capacity_ != 0) {
      this->string_ = new char[this->capacity_];
    } else {
      this->string_ = nullptr;
    }
    for (size_t j = 0; j < this->size_; ++j) {
      this->string_[j] = other[j];
    }
  } else {
    this->string_ = nullptr;
    this->size_ = 0;
    this->capacity_ = 0;
  }
}
String::String(const char* other, size_t buffer) {
  if ((buffer != 0) & (other != nullptr)) {
    this->size_ = buffer;
    this->capacity_ = buffer;
    this->string_ = new char[capacity_];
    for (size_t i = 0; i < this->size_; ++i) {
      this->string_[i] = other[i];
    }
  } else {
    this->string_ = nullptr;
    this->size_ = 0;
    this->capacity_ = 0;
  }
}
String::String(const String& other) {
  this->size_ = other.size_;
  this->capacity_ = other.capacity_;
  if (this->capacity_ != 0) {
    this->string_ = new char[this->capacity_];
  } else {
    this->string_ = nullptr;
  }
  for (size_t i = 0; i < this->size_; i++) {
    this->string_[i] = other[i];
  }
}
String& String::operator=(const String& other) {
  if (*this != other) {
    this->size_ = other.size_;
    this->capacity_ = other.capacity_;
    delete[] this->string_;
    if (this->capacity_ != 0) {
      this->string_ = new char[this->capacity_];
    } else {
      this->string_ = nullptr;
      return *this;
    }
    for (size_t i = 0; i < this->size_; i++) {
      this->string_[i] = other[i];
    }
  }
  return *this;
}
String::~String() {
  delete[] string_;
}
const char& String::operator[](size_t index) const {
  return this->string_[index];
}
char& String::operator[](size_t index) {
  return this->string_[index];
}
char& String::At(size_t index) {
  if (index < this->size_) {
    return this->string_[index];
  }
  throw StringOutOfRange{};
}
const char& String::At(size_t index) const {
  if (index < this->size_) {
    return this->string_[index];
  }
  throw StringOutOfRange{};
}
char& String::Front() {
  return *this->string_;
}
const char& String::Front() const {
  return *this->string_;
}
char& String::Back() {
  return *(this->string_ + this->size_ - 1);
}
const char& String::Back() const {
  return *(this->string_ + this->size_ - 1);
}
char* String::CStr() {
  return this->string_;
}
const char* String::CStr() const {
  return this->string_;
}
char* String::Data() {
  return this->string_;
}
const char* String::Data() const {
  return this->string_;
}
bool String::Empty() {
  return this->size_ == 0;
}
bool String::Empty() const {
  return this->size_ == 0;
}
size_t String::Size() {
  return this->size_;
}
size_t String::Size() const {
  return this->size_;
}
size_t String::Length() {
  return this->size_;
}
size_t String::Length() const {
  return this->size_;
}
size_t String::Capacity() {
  return this->capacity_;
}
size_t String::Capacity() const {
  return this->capacity_;
}
void String::Clear() {
  this->size_ = 0;
}
void String::Swap(String& other) {
  String tmp = other;
  other = *this;
  *this = tmp;
}
void String::PopBack() {
  if (size_ >= 1) {
    this->string_[this->size_ - 1] = '\0';
    this->size_--;
  }
}
void String::PushBack(char symbol) {
  if (this->size_ == this->capacity_) {
    this->Reserve();
  }
  this->string_[size_] = symbol;
  this->size_++;
}
String& String::operator+=(const String& other) {
  if (other.string_ != nullptr) {
    if (this->size_ + other.size_ > this->capacity_) {
      this->Reserve(2 * std::max(other.size_, this->size_));
    }
    for (size_t i = 0; i < other.size_; i++) {
      this->string_[this->size_ + i] = other.string_[i];
    }
    this->size_ += other.size_;
  }
  return *this;
}
void String::Resize(size_t new_size, char symbol) {
  if (new_size < this->size_) {
    for (size_t i = new_size; i < this->size_; i++) {
      this->PopBack();
    }
  } else if (new_size > this->size_) {
    this->Reserve(2 * std::max(new_size, this->size_));
    for (size_t i = this->size_; i < new_size; i++) {
      this->string_[i] = symbol;
    }
  }
  this->size_ = new_size;
}
void String::Reserve(size_t new_capacity) {
  if (new_capacity > this->capacity_) {
    String tmp = *this;
    delete[] string_;
    this->string_ = new char[new_capacity];
    this->capacity_ = new_capacity;
    for (size_t i = 0; i < tmp.size_; i++) {
      this->string_[i] = tmp[i];
    }
  }
}
void String::Reserve() {
  String tmp = *this;
  delete[] string_;
  this->string_ = new char[2 * this->capacity_ + 1];
  this->capacity_ = 2 * this->capacity_ + 1;
  for (size_t i = 0; i < tmp.size_; i++) {
    this->string_[i] = tmp[i];
  }
}
void String::ShrinkToFit() {
  String tmp = *this;
  delete[] this->string_;
  this->capacity_ = this->size_;
  this->string_ = new char[this->capacity_];
  for (size_t i = 0; i < tmp.size_; i++) {
    this->string_[i] = tmp[i];
  }
}
String operator+(const String& first, const String& second) {
  String tmp = first;
  tmp += second;
  return tmp;
}
bool operator==(const String& first, const String& second) {
  if (first.size_ != second.size_) {
    return false;
  }
  for (size_t i = 0; i < first.size_; i++) {
    if (first.string_[i] != second.string_[i]) {
      return false;
    }
  }
  return true;
}
bool operator!=(const String& first, const String& second) {
  return !(first == second);
}
bool operator<(const String& first, const String& second) {
  for (size_t i = 0; i < std::min(first.size_, second.size_); i++) {
    if (first.string_[i] < second.string_[i]) {
      return true;
    }
    if (first.string_[i] > second.string_[i]) {
      return false;
    }
  }
  return first.size_ < second.size_;
}
bool operator>(const String& first, const String& second) {
  for (size_t i = 0; i < std::min(first.size_, second.size_); i++) {
    if (first.string_[i] > second.string_[i]) {
      return true;
    }
    if (first.string_[i] < second.string_[i]) {
      return false;
    }
  }
  return first.size_ > second.size_;
}
bool operator<=(const String& first, const String& second) {
  for (size_t i = 0; i < std::min(first.size_, second.size_); i++) {
    if (first.string_[i] < second.string_[i]) {
      return true;
    }
    if (first.string_[i] > second.string_[i]) {
      return false;
    }
  }
  return first.size_ <= second.size_;
}
bool operator>=(const String& first, const String& second) {
  for (size_t i = 0; i < std::min(first.size_, second.size_); i++) {
    if (first.string_[i] > second.string_[i]) {
      return true;
    }
    if (first.string_[i] < second.string_[i]) {
      return false;
    }
  }
  return first.size_ >= second.size_;
}
std::ostream& operator<<(std::ostream& os, String str) {
  for (size_t i = 0; i < str.size_; i++) {
    os << str.string_[i];
  }
  return os;
}