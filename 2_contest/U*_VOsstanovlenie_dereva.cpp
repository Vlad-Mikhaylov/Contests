#include <iostream>
class Node {
 public:
  int value;
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
  int height = 0;
};

struct BST {
 public:
  Node* root_ = nullptr;
  Node* prev_ = nullptr;
  Node* parent = nullptr;
  int max_height = 0;
  void Push(int);
  void PostOrder(Node*);
  void CheckFROot(Node*, Node*, int);
  bool IsRoot(Node*);
  void Clear(Node*);
};
void BST::Push(int cur_value) {
  auto new_node = new Node;
  new_node->value = cur_value;
  Node* cur_node = this->root_;
  if (IsRoot(root_)) {
    this->root_ = new_node;
    new_node->height = 1;
    max_height = new_node->height;
    prev_ = this->root_;
    return;
  }
  if (prev_->value > cur_value) {
    new_node->parent = prev_;
    prev_->left = new_node;
    new_node->height = prev_->height + 1;
    prev_ = new_node;
    return;
  }
  while (true) {
    if (this->IsRoot(cur_node)) {
      break;
    }
    parent = cur_node;
    if (cur_value > parent->value) {
      cur_node = cur_node->right;
      continue;
    }
    if (cur_value < parent->value) {
      cur_node = cur_node->left;
      continue;
    }
    delete new_node;
    return;
  }
  new_node->parent = parent;
  prev_ = cur_node;
  this->CheckFROot(new_node, cur_node, cur_value);
}
void BST::PostOrder(Node* begin) {
  if (begin == nullptr) {
    return;
  }
  PostOrder(begin->left);
  PostOrder(begin->right);
  std::cout << begin->value << ' ';
}
bool BST::IsRoot(Node* node) {
  return node == nullptr;
}
void BST::Clear(Node* root) {
  if (this->IsRoot(root)) {
    return;
  }
  if (this->IsRoot(root->left) && this->IsRoot(root->right)) {
    delete root;
    return;
  }
  if (!this->IsRoot(root->right)) {
    Clear(root->right);
  }
  if (!this->IsRoot(root->left)) {
    Clear(root->left);
  }
  delete root;
}
void BST::CheckFROot(Node* node, Node* cur_node, int cur_value) {
  if (node->parent == nullptr) {
    node->parent = parent;
    prev_ = node;
    this->root_ = cur_node;
    node->height = 1;
    if (node->height < max_height) {
      max_height = node->height;
    }
    return;
  }
  node->parent = parent;
  prev_ = node;
  if (cur_value > parent->value) {
    parent->right = node;
  } else if (cur_value < parent->value) {
    parent->left = node;
  }
  node->height = parent->height;
  node->height += 1;
  if (node->height < max_height) {
    max_height = node->height;
  }
}
int main() {
  BST binary_tree;
  int n;
  int value;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> value;
    binary_tree.Push(value);
  }
  binary_tree.PostOrder(binary_tree.root_);
  binary_tree.Clear(binary_tree.root_);
  return 0;
}