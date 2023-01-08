#include <iostream>

class BinarySearchTree {
private:
  struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
  };
  TreeNode* root;

  void insert(int val, TreeNode*& node) {
    if (node == nullptr) {
      node = new TreeNode{val, nullptr, nullptr};
    } else if (val < node->value) {
      insert(val, node->left);
    } else {
      insert(val, node->right);
    }
  }

  bool search(int val, TreeNode* node) {
    if (node == nullptr) {
      return false;
    } else if (val == node->value) {
      return true;
    } else if (val < node->value) {
      return search(val, node->left);
    } else {
      return search(val, node->right);
    }
  }

  void deleteNode(int val, TreeNode*& node) {
    if (node == nullptr) {
      return;
    } else if (val < node->value) {
      deleteNode(val, node->left);
    } else if (val > node->value) {
      deleteNode(val, node->right);
    } else {
      if (node->left == nullptr && node->right == nullptr) {
        delete node;
        node = nullptr;
      } else if (node->left == nullptr) {
        TreeNode* temp = node;
        node = node->right;
        delete temp;
      } else if (node->right == nullptr) {
        TreeNode* temp = node;
        node = node->left;
        delete temp;
      } else {
        int temp = findMin(node->right);
        node->value = temp;
        deleteNode(temp, node->right);
      }
    }
  }

  int findMin(TreeNode* node) {
    if (node->left == nullptr) {
      return node->value;
    } else {
      return findMin(node->left);
    }
  }

public:
  BinarySearchTree() : root(nullptr) {}

  void insert(int val) {
    insert(val, root);
  }

  bool search(int val) {
    return search(val, root);
  }

  void deleteNode(int val) {
    deleteNode(val, root);
  }
};

int main() {
  BinarySearchTree tree;
  tree.insert(5);
  tree.insert(3);
  tree.insert(7);
  tree.insert(2);
  tree.insert(4);
  tree.insert(6);
  tree.insert(8);

  std::cout << tree.search(3) << std::endl; // True
  std::cout << tree.search(9) << std::endl; // False

  tree.deleteNode(3);
  std::cout << tree.search(3) << std::endl; // False
  
  return 0;
}
