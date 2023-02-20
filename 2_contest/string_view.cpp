#include "string_view.h"
#include <cstring>

StringView::StringView() : string_(nullptr), length_{} {
}
StringView::StringView(const char* instring, size_t size) : string_(instring), length_(size) {
}
StringView::StringView(const char* instring) : string_(instring), length_(std::strlen(instring)) {
}
const char& StringView::operator[](size_t i) const {
  return string_[i];
}
const char& StringView::At(size_t idx) const {
  if (idx >= length_) {
    throw StringViewOutOfRange{};
  } else {
    return string_[idx];
  }
}
const char& StringView::Front() const {
  return string_[0];
}
const char& StringView::Back() const {
  return string_[length_ - 1];
}
size_t StringView::Size() const {
  return length_;
}
size_t StringView::Length() const {
  return length_;
}
bool StringView::Empty() const {
  return length_ == 0;
}
const char* StringView::Data() const {
  return string_;
}
void StringView::Swap(StringView& outstring) {
  auto copy = *this;
  *this = outstring;
  outstring = copy;
}
void StringView::RemovePrefix(size_t prefix) {
  string_ += prefix;
  length_ -= prefix;
}
void StringView::RemoveSuffix(size_t suffix) {
  length_ -= suffix;
}
StringView StringView::Substr(size_t position, size_t num) const {
  if (position > length_) {
    throw StringViewOutOfRange{};
  } else {
    return StringView(string_ + position, (num < length_ - position ? num : length_ - position));
  }
}