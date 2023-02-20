#include <iostream>

class Node {
 public:
  int data;
  Node* next;
};

class Stack {
 private:
  Node* end_ = nullptr;

 public:
  void Push(int data);
  bool IsEmpty();
  int Get();
  void Pop();
  void Delete();
};

void Stack::Push(int data) {
  auto new_node = new Node;
  new_node->data = data;
  new_node->next = this->end_;
  this->end_ = new_node;
}
bool Stack::IsEmpty() {
  return (this->end_) == nullptr;
}
int Stack::Get() {
  if (!IsEmpty()) {
    return this->end_->data;
  }
  exit(1);
}
void Stack::Pop() {
  Node* new_node;
  if (this->end_ != nullptr) {
    new_node = end_;
    end_ = new_node->next;
    delete new_node;
  }
}
bool IsNum(char a) {
  return (static_cast<int>(a) >= 48 && static_cast<int>(a) <= 57);
}

bool IsOper(char a) {
  return (static_cast<int>(a) == 42 || static_cast<int>(a) == 43 || static_cast<int>(a) == 45);
}
int Oper(char oper, int prv, int prprv) {
  if (oper == '*') {
    return prv * prprv;
  }
  if (oper == '+') {
    return prv + prprv;
  }
  if (oper == '-') {
    return prprv - prv;
  }
  return 0;
}
void Stack::Delete() {
  while (!IsEmpty()) {
    Pop();
  }
}
int main() {
  Stack numerals;
  auto str = new char[10000];
  int i = 0;
  int prv;
  int prprv;
  while (std::cin) {
    std::cin >> str[i];
    if (IsNum(str[i])) {
      numerals.Push(static_cast<int>(str[i]) - '0');
    }
    if (IsOper(str[i])) {
      prv = numerals.Get();
      numerals.Pop();
      prprv = numerals.Get();
      numerals.Pop();
      numerals.Push(Oper(str[i], prv, prprv));
    }
    i++;
  }
  std::cout << numerals.Get();
  numerals.Delete();
  delete[] str;
  return 0;
}
