#include <iostream>
struct Node {
 public:
  int value;
  Node* left;
  Node* right;
  Node* parent = nullptr;
};

class Output {
 public:
  Node* node;
  bool is_root = true;
};

struct BST {
 public:
  void PreOrderSearch(Node* root) {
    if (root != nullptr) {
      std::cout << root->value;
      PreOrderSearch(root->left);
      PreOrderSearch(root->right);
    }
  }
  void Push(int x, Node* root, Output& output) {
    if (root == nullptr) {
      auto new_node = new Node;
      new_node->value = x;
      new_node->left = nullptr;
      new_node->right = nullptr;
      if (output.is_root) {
        output.node = new_node;
        output.is_root = false;
      }
    } else if (x < root->value) {
      if (root->left == nullptr) {
        auto new_node = new Node;
        new_node->value = x;
        new_node->left = nullptr;
        new_node->right = nullptr;
        root->left = new_node;
      } else {
        Push(x, root->left, output);
      }
    } else if (x > root->value) {
      if (root->right == nullptr) {
        auto new_node = new Node;
        new_node->value = x;
        new_node->left = nullptr;
        new_node->right = nullptr;
        root->right = new_node;
      } else {
        Push(x, root->right, output);
      }
    }
  }
  void RemoveTree(Node* root) {
    if (root != nullptr) {
      RemoveTree(root->left);
      RemoveTree(root->right);
      delete root;
    }
  }
  int HieghtBST(Node* root) {
    if (root == nullptr) {
      return 0;
    }
    int left_height;
    int right_height;
    if (root->left != nullptr) {
      left_height = HieghtBST(root->left);
    } else {
      left_height = -1;
    }
    if (root->right != nullptr) {
      right_height = HieghtBST(root->right);
    } else {
      right_height = -1;
    }
    return std::max(left_height, right_height) + 1;
  }
};

int main() {
  BST binary_tree;
  Output output;
  output.node = nullptr;
  int value;
  while (true) {
    std::cin >> value;
    if (value == 0) {
      break;
    }
    binary_tree.Push(value, output.node, output);
  }
  std::cout << binary_tree.HieghtBST(output.node) + 1;
  binary_tree.RemoveTree(output.node);
  return 0;
}