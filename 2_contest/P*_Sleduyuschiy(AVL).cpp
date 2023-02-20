#include <iostream>
struct Node {
  Node* left = nullptr;
  Node* right = nullptr;
  int value;
  int height = 0;
};
class AVLTree {
 public:
  Node* root_ = nullptr;
  void Insert(int value) {
    root_ = Insert(root_, value);
  }
  int Find(int value) {
    int res = 1000000001;
    return Find(root_, value, res);
  }
  bool Find1(int value) {
    return Find1(root_, value);
  }
  void Erase(int value) {
    root_ = Erase(root_, value);
  }
  Node* Erase(Node*, int);
  bool Find1(Node*, int);
  int Find(Node*, int, int);
  Node* FindMin(Node*);
  Node* UnlinkMin(Node*);
  Node* Insert(Node*, int);
  int Height(Node*);
  int BalanceFactor(Node*);
  void MeasureHight(Node*);
  Node* RightRotate(Node*);
  Node* LeftRotate(Node*);
  Node* FixBalance(Node*);
  void Clear(Node*);
};
void AVLTree::Clear(Node* node) {
  if (node->left != nullptr) {
    Clear(node->left);
  }
  if (node->right != nullptr) {
    Clear(node->right);
  }
  delete node;
}
Node* AVLTree::Erase(Node* node, int value) {
  if (node == nullptr) {
    return node;
  }
  if (node->value == value) {
    if (node->right == nullptr) {
      auto temp = node->left;
      delete node;
      return FixBalance(temp);
    }
    auto right_min = FindMin(node->right);
    node->right = UnlinkMin(node->right);
    right_min->left = node->left;
    right_min->right = node->right;
    delete node;
    return FixBalance(right_min);
  }
  if (value < node->value) {
    node->left = Erase(node->left, value);
  } else {
    node->right = Erase(node->right, value);
  }
  return FixBalance(node);
}

Node* AVLTree::FindMin(Node* node) {
  if (node->left == nullptr) {
    return node;
  }
  return FindMin(node->left);
}

Node* AVLTree::UnlinkMin(Node* node) {
  if (node->left == nullptr) {
    return node->right;
  }
  node->left = UnlinkMin(node->left);
  return FixBalance(node);
}

bool AVLTree::Find1(Node* node, int value) {
  if (node == nullptr) {
    return false;
  }
  if (node->value == value) {
    return true;
  }
  if (value < node->value) {
    return Find1(node->left, value);
  }
  return Find1(node->right, value);
}

int AVLTree::Find(Node* node, int value, int res) {
  if (node == nullptr && res == 1000000001) {
    return -1;
  }
  if (node == nullptr) {
    return res;
  }
  if ((node->value >= value) && (res > node->value)) {
    res = node->value;
  }
  if (value < node->value) {
    return Find(node->left, value, res);
  }
  return Find(node->right, value, res);
}

Node* AVLTree::Insert(Node* node, int value) {
  if (node == nullptr) {
    auto new_node = new Node;
    new_node->value = value;
    return new_node;
  }
  if (value <= node->value) {
    node->left = Insert(node->left, value);
  } else {
    node->right = Insert(node->right, value);
  }
  return FixBalance(node);
}

int AVLTree::Height(Node* node) {
  return node == nullptr ? 0 : node->height;
}

int AVLTree::BalanceFactor(Node* node) {
  return node == nullptr ? 0 : Height(node->right) - Height(node->left);
}

void AVLTree::MeasureHight(Node* node) {
  if (node == nullptr) {
    return;
  }
  node->height = 1 + std::max(Height(node->left), Height(node->right));
}

Node* AVLTree::RightRotate(Node* p) {
  Node* q = p->left;
  p->left = q->right;
  q->right = p;
  MeasureHight(p);
  MeasureHight(q);
  return q;
}

Node* AVLTree::LeftRotate(Node* q) {
  Node* p = q->right;
  q->right = p->left;
  p->left = q;
  MeasureHight(q);
  MeasureHight(p);
  return p;
}
Node* AVLTree::FixBalance(Node* node) {
  MeasureHight(node);
  if (BalanceFactor(node) == 2) {
    if (BalanceFactor(node->right) == -1) {
      node->right = RightRotate(node->right);
    }
    return LeftRotate(node);
  }
  if (BalanceFactor(node) == -2) {
    if (BalanceFactor(node->left) == 1) {
      node->left = LeftRotate(node->left);
    }
    return RightRotate(node);
  }
  return node;
}

int Operation(char* comman_list, AVLTree*& treap, char last_op, int last_v) {
  int cur_value, lvalue;
  std::cin >> cur_value;
  lvalue = -1;
  if (comman_list[0] == '+') {
    if (last_op == '?') {
      cur_value = (last_v + cur_value) % 1000000000;
      if (!(treap->Find1(cur_value))) {
        treap->Insert(cur_value);
      }
    } else {
      if (!(treap->Find1(cur_value))) {
        treap->Insert(cur_value);
      }
    }
  }
  if (comman_list[0] == '?') {
    lvalue = treap->Find(cur_value);
    std::cout << lvalue << std::endl;
  }
  return lvalue;
}

int main() {
  auto avl = new AVLTree;
  int n;
  std::cin >> n;
  char operation[10];
  char last_op = 'e';
  int last_value = -1;
  for (int i = 0; i < n; ++i) {
    std::cin >> operation;
    last_value = Operation(operation, avl, last_op, last_value);
    last_op = operation[0];
  }
  avl->Clear(avl->root_);
  delete avl;
}