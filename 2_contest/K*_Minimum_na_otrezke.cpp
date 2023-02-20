#include <iostream>
#include <cstring>
class Node {
 public:
  int cur_min;
  int data;
  Node* next;
};

class Stack {
  Node* end_ = nullptr;

 public:
  void Push(int data);
  bool IsEmpty();
  int Get();
  void Pop();
  void Clear();
  int GetMin();
};

void Stack::Push(int data) {
  auto new_node = new Node;
  new_node->data = data;
  new_node->cur_min = std::min(data, ((end_ == nullptr) ? data : (end_->cur_min)));
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
  Node* new_node;
  if (this->end_ != nullptr) {
    new_node = end_;
    end_ = new_node->next;
    delete new_node;
  }
}

int Stack::GetMin() {
  if (!IsEmpty()) {
    return end_->cur_min;
  }
  return -1;
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
    if (stack_2.IsEmpty() && !stack_1.IsEmpty()) {
      while (!stack_1.IsEmpty()) {
        stack_2.Push(stack_1.Get());
        stack_1.Pop();
      }
    } else if (stack_2.IsEmpty() && stack_1.IsEmpty()) {
      return -1;
    }
    return stack_2.Get();
  }
  int GetMin() {
    if (stack_2.IsEmpty() && !stack_1.IsEmpty()) {
      return stack_1.GetMin();
    }
    if (stack_2.IsEmpty() && stack_1.IsEmpty()) {
      return -1;
    }
    if (!stack_2.IsEmpty() && stack_1.IsEmpty()) {
      return stack_2.GetMin();
    }
    return std::min(stack_1.GetMin(), stack_2.GetMin());
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
  Queue queue;
  int n;
  int k;
  int element;
  std::cin >> n >> k;
  for (int i = 0; i < n; i++) {
    std::cin >> element;
    if (i < k - 1) {
      queue.Push(element);
    } else if (i == k - 1) {
      queue.Push(element);
      std::cout << queue.GetMin() << '\n';
    } else if (i > k - 1) {
      queue.Push(element);
      queue.Pop();
      std::cout << queue.GetMin() << '\n';
    }
  }
  queue.Clear();
  return 0;
}