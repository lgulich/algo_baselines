#ifndef GRAPH_TRAVERSAL_H_
#define GRAPH_TRAVERSAL_H_

#include <queue>
#include <stack>

#include "graph/types.h"

// T~O(N+E), S~O(N)
inline vector<int> bfsTraversal(const AdjacencyList& graph, const int start) {
  if (graph.empty()) { return {}; }

  vector<int> order;
  order.reserve(graph.size());

  queue<int> open;
  open.push(start);

  vector<bool> closed(graph.size(), false);
  closed[start] = true;

  while (!open.empty()) {
    const int current = open.front();
    open.pop();
    order.push_back(current);

    for (const int child : graph.at(current)) {
      if (closed[child]) { continue; }

      open.push(child);
      closed[child] = true;
    }
  }

  return order;
}

// T~O(N+E), S~O(N)
inline vector<int> dfsTraversal(const AdjacencyList& graph, const int start) {
  if (graph.empty()) { return {}; }

  vector<int> order;
  order.reserve(graph.size());

  stack<int> open;
  open.push(start);

  vector<bool> closed(graph.size(), false);
  closed[start] = true;

  while (!open.empty()) {
    const int current = open.top();
    open.pop();
    order.push_back(current);

    for (const int child : graph.at(current)) {
      if (closed[child]) { continue; }

      open.push(child);
      closed[child] = true;
    }
  }

  return order;
}

#endif  // GRAPH_TRAVERSAL_H_
