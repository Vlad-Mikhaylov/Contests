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
  void GetRootOfRightest(Node* root) {
    if (root->right == nullptr) {
      root = root->left;
      while (root->right != nullptr) {
        root = root->right;
      }
      std::cout << root->value;
    } else {
      if ((root->right)->right != nullptr) {
        GetRootOfRightest(root->right);
      } else {
        if ((root->right)->left == nullptr) {
          std::cout << root->value;
        } else {
          root = (root->right)->left;
          while (root->right != nullptr) {
            root = root->right;
          }
          std::cout << root->value;
        }
      }
    }
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
  binary_tree.GetRootOfRightest(output.node);
  binary_tree.RemoveTree(output.node);
  return 0;
}