#ifndef GRAPH_TOPOLOGICAL_SORT_H_
#define GRAPH_TOPOLOGICAL_SORT_H_

#include <algorithm>

#include "graph/mutation.h"
#include "graph/types.h"

inline void dfsExplore(
    const int node, const AdjacencyList& graph, vector<int>* order,
    vector<bool>* closed) {
  if (closed->at(node)) {
    return;
  }

  closed->at(node) = true;

  for (const int child : graph[node]) {
    dfsExplore(child, graph, order, closed);
  }

  order->push_back(node);
}

// T~O(N+E), S~O(N)
// We assume that input graph has no loops.
inline vector<int> topologicalSortDfs(const AdjacencyList& graph) {
  vector<int> order;
  order.reserve(order.size());

  vector<bool> closed(graph.size(), false);

  for (int node = 0; node < graph.size(); ++node) {
    if (closed[node]) {
      continue;
    }

    dfsExplore(node, graph, &order, &closed);
  }

  std::reverse(order.begin(), order.end());
  return order;
}

// T~O(N+E), S~O(N+E)
inline vector<int> topologicalSortKahn(const AdjacencyList& graph) {
  // T~O(E), S~O(N)
  vector<int> num_open_requirements(graph.size(), 0);
  for (const auto& children : graph) {
    for (const int child : children) {
      ++num_open_requirements[child];
    }
  }

  // T~O(N), S~O(N)
  vector<int> open;
  open.reserve(graph.size());
  for (int node = 0; node < graph.size(); ++node) {
    if (num_open_requirements[node] == 0) {
      open.push_back(node);
    }
  }

  // T~O(N), S~O(N)
  vector<int> order;
  order.reserve(order.size());

  // T~O(N+E), S~O(1)
  while (!open.empty()) {
    const int current = open.back();
    open.pop_back();
    order.push_back(current);

    for (const int dependency : graph[current]) {
      --num_open_requirements[dependency];
      if (num_open_requirements[dependency] == 0) {
        open.push_back(dependency);
      }
    }
  }

  if (order.size() != graph.size()) {
    throw "Graph contains loop.";
  }

  return order;
}

#endif  // GRAPH_TOPOLOGICAL_SORT_H_
