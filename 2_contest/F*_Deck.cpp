#include <iostream>
#include <cstring>
struct Traceback {
  int value;
  bool error;
};
class Node {
 public:
  int data;
  Node* next = nullptr;
  Node* prev = nullptr;
};

class Dequeue {
 private:
  Node* end_ = nullptr;
  Node* begin_ = nullptr;
  size_t size_ = 0;

 public:
  void PushFront(int data);
  void PushBack(int data);
  bool IsEmpty();
  Traceback GetFront();
  Traceback GetBack();
  int DetBack();
  void PopBack();
  void PopFront();
  void Clear();
  size_t GetSize();
  void SetDeq();
};
void Dequeue::SetDeq() {
  this->end_ = nullptr;
  this->begin_ = nullptr;
  this->size_ = 0;
}
void Dequeue::PushBack(int data) {
  auto new_node = new Node;
  new_node->data = data;
  new_node->next = nullptr;
  new_node->prev = this->end_;
  this->end_ = new_node;
  this->size_++;
  if (this->size_ == 1) {
    this->begin_ = new_node;
    return;
  }
  (new_node->prev)->next = new_node;
}
void Dequeue::PushFront(int data) {
  auto new_node = new Node;
  new_node->data = data;
  new_node->prev = nullptr;
  new_node->next = this->begin_;
  this->begin_ = new_node;
  this->size_++;
  if (this->size_ == 1) {
    this->end_ = new_node;
    return;
  }
  (new_node->next)->prev = new_node;
}
bool Dequeue::IsEmpty() {
  return size_ <= 0;
}
Traceback Dequeue::GetFront() {
  Traceback output;
  if (!IsEmpty()) {
    output.value = this->begin_->data;
    return output;
  }
  output.error = -1;
  return output;
}
Traceback Dequeue::GetBack() {
  Traceback output;
  if (!IsEmpty()) {
    output.value = this->end_->data;
    return output;
  }
  output.error = -1;
  return output;
}
void Dequeue::PopBack() {
  if (this->size_ == 1) {
    delete this->begin_;
    begin_ = nullptr;
    end_ = nullptr;
    this->size_--;
    return;
  }
  Node* new_node;
  if (end_ != nullptr) {
    new_node = end_;
    end_ = new_node->prev;
    this->size_--;
    delete new_node;
  }
}
void Dequeue::PopFront() {
  if (this->size_ == 1) {
    delete this->begin_;
    this->begin_ = nullptr;
    this->end_ = nullptr;
    this->size_--;
    return;
  }
  if (!IsEmpty()) {
    Node* new_node;
    new_node = begin_;
    this->begin_ = new_node->next;
    this->size_--;
    delete new_node;
  }
}
void Dequeue::Clear() {
  if (IsEmpty()) {
    return;
  }
  if (this->size_ == 1) {
    delete this->end_;
    this->size_--;
    return;
  }
  Node* next_to_clear = this->begin_->next;
  delete this->begin_;
  this->begin_ = next_to_clear;
  this->size_--;
  Clear();
}
size_t Dequeue::GetSize() {
  return this->size_;
}
int main() {
  int k;
  std::cin >> k;
  char command[30];
  Dequeue deck;
  int n;
  for (int i = 0; i < k; i++) {
    std::cin >> command;
    if (std::strcmp(command, "push_front") == 0) {
      std::cin >> n;
      deck.PushFront(n);
      std::cout << "ok\n";
      continue;
    }
    if (std::strcmp(command, "push_back") == 0) {
      std::cin >> n;
      deck.PushBack(n);
      std::cout << "ok\n";
      continue;
    }
    if (std::strcmp(command, "pop_front") == 0) {
      if (!deck.IsEmpty()) {
        std::cout << deck.GetFront().value << '\n';
        deck.PopFront();
      } else {
        std::cout << "error\n";
        continue;
      }
      continue;
    }
    if (std::strcmp(command, "pop_back") == 0) {
      if (!deck.IsEmpty()) {
        std::cout << deck.GetBack().value << '\n';
        deck.PopBack();
      } else {
        std::cout << "error\n";
        continue;
      }
      continue;
    }
    if (std::strcmp(command, "front") == 0) {
      if (deck.GetSize() != 0) {
        std::cout << deck.GetFront().value << '\n';
      } else {
        std::cout << "error\n";
      }
      continue;
    }
    if (std::strcmp(command, "back") == 0) {
      if (deck.GetSize() != 0) {
        std::cout << deck.GetBack().value << '\n';
      } else {
        std::cout << "error\n";
      }
      continue;
    }
    if (std::strcmp(command, "size") == 0) {
      std::cout << deck.GetSize() << '\n';
      continue;
    }
    if (std::strcmp(command, "clear") == 0) {
      if (!deck.IsEmpty()) {
        deck.Clear();
      }
      deck.SetDeq();
      std::cout << "ok\n";
      continue;
    }
    if (std::strcmp(command, "exit") == 0) {
      if (!deck.IsEmpty()) {
        deck.Clear();
      }
      std::cout << "bye";
      break;
    }
  }
  if (!deck.IsEmpty()) {
    deck.Clear();
  }
  return 0;
}