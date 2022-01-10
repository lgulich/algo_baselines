#ifndef TREE_TYPES_H_
#define TREE_TYPES_H_

#include <vector>
#include <iostream>

using namespace std;

struct Tree {
  int value;
  vector<Tree*> children;

  Tree(const int value) : value(value) {}
};

inline void deleteTree(Tree* tree) {
  if (!tree) {
    return;
  }

  for (const auto child : tree->children) {
    deleteTree(child);
  }
  delete tree;
}

inline void print(const Tree* tree) {
  std::cout << tree->value << std::endl;
  for (const auto child : tree->children) {
    std::cout << "->" << child->value << std::endl;
  }

  for (const auto child : tree->children) {
    print(child);
  }
}

#endif  // TREE_TYPES_H_
