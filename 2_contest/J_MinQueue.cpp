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
  int m;
  int size = 0;
  int n;
  std::cin >> m;
  char command[30];
  for (int i = 0; i < m; i++) {
    std::cin >> command;
    if (!std::strcmp(command, "enqueue")) {
      std::cin >> n;
      size++;
      queue.Push(n);
      std::cout << "ok\n";
      continue;
    }
    if (!std::strcmp(command, "dequeue")) {
      if (!queue.IsEmpty()) {
        std::cout << queue.Get() << '\n';
        queue.Pop();
        size--;
      } else {
        std::cout << "error\n";
        continue;
      }
      continue;
    }
    if (!std::strcmp(command, "front")) {
      if (queue.GetMin() != -1) {
        std::cout << queue.Get() << '\n';
      } else {
        std::cout << "error\n";
      }
      continue;
    }
    if (!std::strcmp(command, "size")) {
      std::cout << size << '\n';
      continue;
    }
    if (!std::strcmp(command, "clear")) {
      queue.Clear();
      size = 0;
      std::cout << "ok\n";
      continue;
    }
    if (!std::strcmp(command, "min")) {
      if (queue.GetMin() != -1) {
        std::cout << queue.GetMin() << '\n';
      } else {
        std::cout << "error\n";
      }
      continue;
    }
  }
  queue.Clear();
  return 0;
}