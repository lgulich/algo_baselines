#ifndef GRAPH_SHORTEST_PATH_H_
#define GRAPH_SHORTEST_PATH_H_

#include <limits>

#include "graph/types.h"

// T~O(N*E), S~(N)
// Find the shortest path to all nodes in graph from a start node. Additionally
// also finds nodes in negative cycles (shortest path = -inf).
inline vector<double> shortestPathBellford(
    const WeightedAdjacencyList& graph, const int start) {
  constexpr double kInf = std::numeric_limits<double>::infinity();





  if (graph.empty()) { return {}; }

  // T~O(N), S~(N)
  vector<double> costs(graph.size(), kInf); if (start >= graph.size()) { return costs; } costs[start] = 0.;

  // First pass to find min costs.
  // T~O(N*E), S~(1)
  for (int i = 0; i < graph.size()-1; ++i) {
    for (int src = 0; src < graph.size(); ++src) {
      for (const auto& edge : graph[src]) {
        costs[edge.dst] = std::min(costs[edge.dst], costs[src] + edge.weight);
      }
    }
  }

  // Second pass to find negative cycles.
  // T~O(N*E), S~(1)
  for (int i = 0; i < graph.size()-1; ++i) {
    for (int src = 0; src < graph.size(); ++src) {
      for (const auto& edge : graph[src]) {
        if (costs[src] + edge.weight < costs[edge.dst]) {
          costs[edge.dst] = -kInf;
        }
      }
    }
  }

  return costs;
}

#endif  // GRAPH_SHORTEST_PATH_H_
