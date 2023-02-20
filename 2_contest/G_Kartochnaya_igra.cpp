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
  void Clear();
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
  return -1;
}
void Stack::Pop() {
  if (this->end_ != nullptr) {
    Node* new_node;
    new_node = end_;
    end_ = new_node->next;
    delete new_node;
  }
}

void Stack::Clear() {
  while (!IsEmpty()) {
    Pop();
  }
}

class Queue {
 public:
  Stack stack_1;
  Stack stack_2;
  void Push(int data) {
    stack_1.Push(data);
  }
  int Get() {
    if (stack_2.IsEmpty()) {
      while (!stack_1.IsEmpty()) {
        stack_2.Push(stack_1.Get());
        stack_1.Pop();
      }
    }
    return stack_2.Get();
  }
  bool IsEmpty() {
    return stack_1.IsEmpty() && stack_2.IsEmpty();
  }
  void Pop() {
    if (stack_2.IsEmpty()) {
      while (!stack_1.IsEmpty()) {
        stack_2.Push(stack_1.Get());
        stack_1.Pop();
      }
    }
    stack_2.Pop();
  }
  void Clear() {
    stack_1.Clear();
    stack_2.Clear();
  }
};

int main() {
  Queue set_1;
  Queue set_2;
  int counter = 0;
  int element_1;
  int element_2;
  for (int i = 0; i < 5; i++) {
    std::cin >> element_1;
    set_1.Push(element_1);
  }
  for (int i = 0; i < 5; i++) {
    std::cin >> element_2;
    set_2.Push(element_2);
  }
  while (counter <= 1000000) {
    if (set_1.IsEmpty()) {
      std::cout << "second" << ' ' << counter;
      set_1.Clear();
      set_2.Clear();
      return 0;
    }
    if (set_2.IsEmpty()) {
      std::cout << "first" << ' ' << counter;
      set_1.Clear();
      set_2.Clear();
      return 0;
    }
    element_1 = set_1.Get();
    element_2 = set_2.Get();
    if (element_1 == 0) {
      if (element_2 == 9) {
        set_1.Pop();
        set_1.Push(0);
        set_1.Push(9);
        set_2.Pop();
        counter++;
        continue;
      }
      set_2.Pop();
      set_2.Push(0);
      set_2.Push(element_2);
      set_1.Pop();
      counter++;
      continue;
    }
    if (element_2 == 0) {
      if (element_1 == 9) {
        set_2.Pop();
        set_2.Push(9);
        set_2.Push(0);
        set_1.Pop();
        counter++;
        continue;
      }
      set_1.Pop();
      set_1.Push(element_1);
      set_1.Push(0);
      set_2.Pop();
      counter++;
      continue;
    }
    if (element_2 > element_1) {
      set_2.Pop();
      set_2.Push(element_1);
      set_2.Push(element_2);
      set_1.Pop();
      counter++;
      continue;
    }
    set_1.Pop();
    set_1.Push(element_1);
    set_1.Push(element_2);
    set_2.Pop();
    counter++;
  }
  set_1.Clear();
  set_2.Clear();
  std::cout << "botva";
  return 0;
}