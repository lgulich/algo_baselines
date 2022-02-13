#ifndef DATA_STRUCTURES_BINARY_SEARCH_TREE_H_
#define DATA_STRUCTURES_BINARY_SEARCH_TREE_H_

#include <iostream>

class BinarySearchTree {
 public:
  // T~(1)
  int size() const {
    if (!root_) { return 0; }
    return root_->rank;
  }

  // T~(log(N)) if balanced
  int findLess(const int value) const {
    Node* node = findLessNode(value);
    if (!node) { throw "No node found."; }
    return node->value;
  }

  // T~(log(N)) if balanced
  int findGreater(const int value) const {
    Node* node = findGreaterNode(value);
    if (!node) { throw "No node found."; }
    return node->value;
  }

  // T~(log(N)) if balanced
  int findLessOrEqual(const int value) const {
    Node* node = findLessOrEqualNode(value);
    if (!node) { throw "No node found."; }
    return node->value;
  }

  // T~(log(N)) if balanced
  int findGreaterOrEqual(const int value) const {
    Node* node = findGreaterOrEqualNode(value);
    if (!node) { throw "No node found."; }
    return node->value;
  }

  // T~(log(N)) if balanced
  int countInRange(const int low, const int high) const {
    if (!root_) { return 0; }

    Node* lower = findLessNode(low);
    const int num_lower = lower ? lower->rank : 0;

    Node* higher = findGreaterNode(high);
    const int num_higher = higher ? higher->rank : 0;

    return root_->rank - num_lower - num_higher;
  }

  // T~(log(N)) if balanced
  void insert(const int value) {
    Node* new_node = new Node(value);

    if (!root_) {
      root_ = new_node;
      return;
    }

    Node* parent = root_;

    while (true) {
      ++parent->rank;
      if (value < parent->value) {
        // Node should go to left subtree:
        if (parent->left) {
          parent = parent->left;
        } else {
          parent->left = new_node;
          return;
        }
      } else {
        // Node should go to righ subtree:
        if (parent->right) {
          parent = parent->right;
        } else {
          parent->right = new_node;
          return;
        }
      }
    }
  }

 private:
  struct Node {
    int value;
    int rank = 1;
    Node* left = nullptr;
    Node* right = nullptr;

    Node(const int value) : value(value) {}
  };

  Node* findGreaterOrEqualNode(const int value) const {
    Node* result = nullptr;
    Node* node = root_;

    while (node) {
      if (node->value == value) { return node; }
      if (node->value < value) {
        node = node->right;
      } else {
        result = node;
        node = node->left;
      }
    }

    return result;
  }

  Node* findGreaterNode(const int value) const {
    Node* result = nullptr;
    Node* node = root_;

    while (node) {
      if (node->value <= value) {
        node = node->right;
      } else {
        result = node;
        node = node->left;
      }
    }

    return result;
  }

  Node* findLessOrEqualNode(const int value) const {
    Node* result = nullptr;
    Node* node = root_;

    while (node) {
      if (node->value == value) { return node; }
      if (node->value > value) {
        node = node->left;
      } else {
        result = node;
        node = node->right;
      }
    }

    return result;
  }

  Node* findLessNode(const int value) const {
    Node* result = nullptr;
    Node* node = root_;

    while (node) {
      if (node->value >= value) {
        node = node->left;
      } else {
        result = node;
        node = node->right;
      }
    }

    return result;
  }

  Node* root_ = nullptr;
};

#endif  // DATA_STRUCTURES_BINARY_SEARCH_TREE_H_
