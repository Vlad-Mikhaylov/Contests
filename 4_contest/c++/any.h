#ifndef ANY_H
#define ANY_H
#include <stdexcept>
#include <memory>
class BadAnyCast : public std::bad_cast {
 public:
  [[nodiscard]] const char* what() const noexcept override {
    return "BadAnyCast error";
  }
};

class IHolder {
 public:
  virtual ~IHolder() = default;
  virtual std::unique_ptr<IHolder> Clone() const = 0;
};

//
template <class T>
class AnyHolder : public IHolder {
 public:
  T object;
  std::unique_ptr<IHolder> Clone() const override {
    auto tmp = new AnyHolder<T>(*this);
    std::unique_ptr<IHolder> ptr(tmp);
    return ptr;
  }
  AnyHolder(const T other) {  // NOLINT
    this->object = other;
  }
  IHolder& operator=(const IHolder& other) {
    return *other.Clone();
  }
};

//
class Any {
 public:
  std::unique_ptr<IHolder> object_ptr = nullptr;
  Any() : object_ptr(nullptr) {
  }
  template <class T>
  Any(const T other) {  // NOLINT
    IHolder* tmp = new AnyHolder<T>(other);
    this->object_ptr.reset(tmp);
  }
  Any(const Any& other) {
    if (other.object_ptr != nullptr) {
      std::unique_ptr<IHolder> tmp = (*(other.object_ptr)).Clone();
      this->object_ptr.swap(tmp);
    } else {
      this->object_ptr.reset(nullptr);
    }
  }
  Any& operator=(const Any& other) {
    std::unique_ptr<IHolder> tmp = (*(other.object_ptr)).Clone();
    this->object_ptr.swap(tmp);
    return *this;
  }
  Any& operator=(Any&& other) {
    this->object_ptr.reset();
    this->object_ptr.swap(other.object_ptr);
    return *this;
  }
  template <class T>
  Any& operator=(const T other) {
    IHolder* tmp = new AnyHolder<T>(other);
    this->object_ptr.reset(tmp);
    return *this;
  }
  void Swap(Any& other) {
    Any tmp = other;
    other = *this;
    *this = tmp;
  }
  void Reset() {
    this->object_ptr.reset(nullptr);
  }
  bool HasValue() {
    return object_ptr != nullptr;
  }
};
template <class T>
T AnyCast(const Any& value) {
  if (value.object_ptr != nullptr) {
    auto ptr = dynamic_cast<AnyHolder<T>*>(value.object_ptr.get());
    if (ptr != nullptr) {
      return (*ptr).object;
    }
  }
  throw BadAnyCast{};
}
#endif