#ifndef SHARED_PTR_H
#define SHARED_PTR_H
#include <stdexcept>
class BadWeakPtr : public std::runtime_error {
 public:
  BadWeakPtr() : std::runtime_error("BadWeakPtr") {
  }
};

template <class T>
class SharedPtr {
 public:
  /// @brief
  T* ptr_;
  int* rdublicates_;
  // по умолчанию
  SharedPtr() {
    this->rdublicates_ = nullptr;
    this->ptr_ = nullptr;
  }
  // преобразования
  SharedPtr(T* other_ptr) : ptr_(other_ptr) {  // NOLINT
    if (other_ptr != nullptr) {
      this->rdublicates_ = new int(1);
    } else {
      this->rdublicates_ = nullptr;
    }
  }
  // копирования
  SharedPtr(const SharedPtr& other) {
    this->ptr_ = other.ptr_;
    this->rdublicates_ = other.rdublicates_;
    if (this->rdublicates_ != nullptr) {
      (*(other.rdublicates_))++;
    }
  }
  // копирующее присваивание
  SharedPtr& operator=(const SharedPtr& other) {
    if (this != &other) {
      if (this->rdublicates_ != nullptr) {
        (*(this->rdublicates_))--;
        if (*(this->rdublicates_) <= 1) {
          delete this->rdublicates_;
          delete this->ptr_;
        }
      }
      this->ptr_ = other.ptr_;
      this->rdublicates_ = other.rdublicates_;
      if (other.rdublicates_ != nullptr) {
        (*(other.rdublicates_))++;
      }
    }
    return *this;
  };
  // перемещаяющий
  SharedPtr(SharedPtr&& other) noexcept {
    this->ptr_ = other.ptr_;
    this->rdublicates_ = other.rdublicates_;
    other.ptr_ = nullptr;
    other.rdublicates_ = nullptr;
  }
  // перемещающее присваивание
  SharedPtr& operator=(SharedPtr&& other) noexcept {
    if (this != &other) {
      if (this->rdublicates_ != nullptr) {
        (*(this->rdublicates_))--;
        if (*(this->rdublicates_) <= 0) {
          delete this->rdublicates_;
          delete this->ptr_;
        }
      }
      this->ptr_ = other.ptr_;
      this->rdublicates_ = other.rdublicates_;
      other.ptr_ = nullptr;
      other.rdublicates_ = nullptr;
    }
    return *this;
  }
  // дестурктор
  ~SharedPtr() {
    if (this->ptr_ != nullptr) {
      (*(this->rdublicates_))--;
      if (*(this->rdublicates_) <= 0) {
        delete this->ptr_;
        delete this->rdublicates_;
      }
    } else if ((this->rdublicates_ != nullptr) && (*(this->rdublicates_) <= 1)) {
      delete this->rdublicates_;
    } else if (this->rdublicates_ != nullptr) {
      (*(this->rdublicates_))--;
    }
  }
  void Reset(T* other = nullptr) {
    if (this->rdublicates_ != nullptr) {
      (*(this->rdublicates_))--;
      if (*(this->rdublicates_) <= 0) {
        delete this->rdublicates_;
        delete this->ptr_;
      }
    }
    this->ptr_ = other;
    if (other != nullptr) {
      this->rdublicates_ = new int(1);
    } else {
      this->rdublicates_ = nullptr;
    }
  }
  void Swap(SharedPtr<T>& other) {
    T* tmp = this->ptr_;
    T* tmp_dub = this->rdublicates_;
    this->ptr_ = other.ptr_;
    this->rdublicates_ = other.rdublicates_;
    other.rdublicates_ = tmp_dub;
    other.ptr_ = tmp;
    tmp = nullptr;
    tmp_dub = nullptr;
  }
  T* Get() {
    return this->ptr_;
  }
  T* Get() const {
    return this->ptr_;
  }
  int UseCount() const {
    return this->rdublicates_ != nullptr ? *(this->rdublicates_) : 0;
  }
  T& operator*() const {
    return *ptr_;
  }
  T& operator*() {
    return *ptr_;
  }
  T* operator->() const {
    return ptr_;
  }
  T* operator->() {
    return ptr_;
  }
  explicit operator bool() const {
    return this->ptr_ != nullptr ? true : false;
  }
};
#endif
