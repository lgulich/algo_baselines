#include <stack>

#include "graph/types.h"

// T~O(N+E), S~O(N)
vector<int> dfsOrder(const AdjacencyList& graph, const int start) {
  if (graph.empty()) {
    return {};
  }

  std::vector<int> order;
  order.reserve(graph.size());

  std::stack<int> open;
  open.push(start);

  std::vector<bool> closed(graph.size(), false);
  closed[start] = true;

  while (!open.empty()) {
    const int current = open.top();
    open.pop();
    order.push_back(current);

    for (const int child : graph.at(current)) {
      if (closed[child]) {
        continue;
      }

      open.push(child);
      closed[child] = true;
    }
  }

  return order;
}
