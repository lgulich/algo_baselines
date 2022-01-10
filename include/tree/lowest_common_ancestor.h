#ifndef TREE_LOWEST_COMMON_ANCESTOR_H_
#define TREE_LOWEST_COMMON_ANCESTOR_H_

#include <algorithm>

#include "graph/types.h"
#include "tree/types.h"

inline void eulerianTour(
    Tree* tree, vector<int>* order, vector<int>* depths, const int depth) {
  order->push_back(tree->value);
  depths->push_back(depth);

  for (const auto child : tree->children) {
    eulerianTour(child, order, depths, depth + 1);
    order->push_back(tree->value);
    depths->push_back(depth);
  }
}

// T~(N), S~(N)
inline int lowestCommonAncestor(Tree* tree, const int a, const int b) {
  // S~O(N), because eulerian tour always needs 2*N-1 nodes.
  vector<int> order;
  vector<int> depths;

  // T~O(N), because eulerian tour always needs 2*N-1 nodes.
  eulerianTour(tree, &order, &depths, 0);

  // Find idx of a in eulerian order. T~O(N)
  int lower_idx = std::find(order.begin(), order.end(), a) - order.begin();
  // Find idx of b in eulerian order. T~O(N)
  int upper_idx = std::find(order.begin(), order.end(), b) - order.begin();

  if (upper_idx < lower_idx) {
    std::swap(lower_idx, upper_idx);
  }

  // Find idx of min depth between a and b in eulerian order. T~O(N)
  // For multiple queries this could be improved by using a sparse table (then
  // creation takes N*log(N) time but queries are const time.
  const int min_depth_idx = std::min_element(depths.begin() + lower_idx, depths.begin() + upper_idx) - depths.begin();

  return order[min_depth_idx];
}

#endif  // TREE_LOWEST_COMMON_ANCESTOR_H_
