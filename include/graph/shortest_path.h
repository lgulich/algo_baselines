#ifndef GRAPH_SHORTEST_PATH_H_
#define GRAPH_SHORTEST_PATH_H_

#include <algorithm>
#include <limits>
#include <queue>
#include <unordered_set>

#include "graph/types.h"

// T~O(N*E), S~(N)
// Find the shortest path to all nodes in graph from a start node. Additionally
// also finds nodes in negative cycles (shortest path = -inf).
inline vector<double> shortestPathBellford(
    const WeightedAdjacencyList& graph, const int start) {
  constexpr double kInf = std::numeric_limits<double>::infinity();

  if (graph.empty()) { return {}; }

  // T~O(N), S~(N)
  vector<double> costs(graph.size(), kInf);
  if (start >= graph.size()) { return costs; }
  costs[start] = 0.;

  // First pass to find min costs.
  // T~O(N*E), S~(1)
  for (int i = 0; i < graph.size() - 1; ++i) {
    for (int src = 0; src < graph.size(); ++src) {
      for (const auto& edge : graph[src]) {
        costs[edge.dst] = std::min(costs[edge.dst], costs[src] + edge.weight);
      }
    }
  }

  // Second pass to find negative cycles.
  // T~O(N*E), S~(1)
    for (int src = 0; src < graph.size(); ++src) {
      for (const auto& edge : graph[src]) {
        if (costs[src] + edge.weight < costs[edge.dst]) {
          costs[edge.dst] = -kInf;
        }
      }
  }

  return costs;
}

// T~O(E*log(N)), S~(N)
// Find the shortest path to all nodes in graph from a start node. Additionally
// also finds nodes in negative cycles (shortest path = -inf).
inline vector<int> shortestPathDijkstra(
    const WeightedAdjacencyList& graph, const int start, const int end) {
  struct NodeAndCost {
    int node;
    double cost;

    bool operator<(const NodeAndCost& rhs) const {
      return this->cost < rhs.cost;
    }
  };

  // Start or end are not in graph.
  if (start >= graph.size() || end >= graph.size()) { return {}; }

  // T~O(N), S~(N)
  std::priority_queue<NodeAndCost> open;
  open.push({start, 0.});

  vector<int> parent(graph.size(), -1);
  vector<double> cost(graph.size(), std::numeric_limits<double>::infinity());
  cost[start] = 0.;

  // Label correcting step
  // T~O(E*log(N)), S~(1)
  while (!open.empty()) {
    const int current = open.top().node;
    open.pop();

    for (const auto& edge : graph[current]) {
      const double dst_cost = cost[current] + edge.weight;

      if (dst_cost < cost[edge.dst]) {
        cost[edge.dst] = dst_cost;
        parent[edge.dst] = current;
        // T~O(log(N))
        open.push({edge.dst, dst_cost});
      }
    }
  }

  // Backtrack
  // T~O(N), S~(N)
  vector<int> path;
  int current = end;

  while (parent[current] != -1) {
    path.push_back(current);
    current = parent[current];
  }
  path.push_back(current);

  // If no path is found.
  if (path.back() != start) { return {}; }

  // T~O(N), S~(1)
  std::reverse(path.begin(), path.end());

  return path;
}

#endif  // GRAPH_SHORTEST_PATH_H_
