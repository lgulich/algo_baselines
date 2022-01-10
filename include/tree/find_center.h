#ifndef GRAPH_FIND_CENTER_H_
#define GRAPH_FIND_CENTER_H_

#include "graph/types.h"

// Finds the center node(s) of a graph.
// We assume that the graph has the tree poperty.
// T~(N), S~(N)
inline vector<int> findCenter(const AdjacencyList& graph) {
  if (graph.size() == 1) {
    return {0};
  }

  // Compute out degrees of all nodes.
  vector<int> out_degrees(graph.size(), 0);
  for (int src = 0; src < graph.size(); ++src) {
    out_degrees[src] = graph[src].size();
  }

  // Find all leaves of complete graph.
  vector<int> leaves;
  for (int node = 0; node < graph.size(); ++node) {
    if (out_degrees[node] == 1) {
      leaves.push_back(node);
    }
  }

  int num_touched = leaves.size();
  while (num_touched < graph.size()) {
    // Remove all leaves and find find new leaves.
    vector<int> new_leaves;

    for (const int leaf : leaves) {
      // This removes the leave from the graph.
      out_degrees[leaf] = 0;
      // Now we update the degree of all children of the leaf.
      for (const int child : graph[leaf]) {
        --out_degrees[child];
        if (out_degrees[child] == 1) {
          ++num_touched;
          new_leaves.push_back(child);
        }
      }
    }

    leaves = new_leaves;
  }

  return leaves;
}

#endif  // GRAPH_FIND_CENTER_H_
