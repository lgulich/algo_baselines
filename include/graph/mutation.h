#ifndef GRAPH_MUTATION_H_
#define GRAPH_MUTATION_H_

#include "graph/types.h"

// T~O(E), S~(N+E)
inline AdjacencyList invertAdjacencyList(const AdjacencyList& graph) {
  AdjacencyList inverted(graph.size());

  for (int node = 0; node < graph.size(); ++node) {
    for (int child : graph[node]) {
      inverted[child].push_back(node);
    }
  }

  return inverted;
}

#endif  // GRAPH_MUTATION_H_
