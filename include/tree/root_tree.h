#ifndef TREE_ROOT_TREE_H_
#define TREE_ROOT_TREE_H_

#include "graph/types.h"
#include "tree/types.h"

inline void fillTree(const int node, Tree* parent, const AdjacencyList& graph) {
  Tree* current = new Tree(node);

  if (parent) {
    parent->children.push_back(current);
  }

  for (const int child : graph[node]) {
    // We skip if the child goes back to the parent.
    if (parent && child == parent->value) {
      continue;
    }
    fillTree(child, current, graph);
  }
}

// Convert a graph to a rooted tree.
// We assume that the graph has the tree property.
// T~(N), S~(N)
inline Tree* rootTree(const AdjacencyList& graph, const int root) {
  if (graph.empty()) {
    return nullptr;
  }

  Tree* tree = new Tree(root);
  for (const int child : graph[root]) {
    fillTree(child, tree, graph);
  }
  return tree;
}

#endif  // TREE_ROOT_TREE_H_
