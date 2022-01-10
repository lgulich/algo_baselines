#ifndef GRAPH_TYPES_H_
#define GRAPH_TYPES_H_

#include <iostream>
#include <vector>

using namespace std;

using AdjacencyList = vector<vector<int>>;

inline void print(const AdjacencyList &graph) {
  for (int node = 0; node < graph.size(); ++node) {
    std::cout << node << std::endl;
    for (const int child : graph[node]) {
      std::cout << "->" << child << std::endl;
    }
  }
}

inline AdjacencyList makeUndirected(const AdjacencyList &directed) {
  AdjacencyList undirected = directed;
  for (int src = 0; src < directed.size(); ++src) {
    for (const int dst : directed[src]) {
      if (std::find(undirected[dst].begin(), undirected[dst].end(), src) ==
          undirected[dst].end()) {
        undirected[dst].push_back(src);
      }
    }
  }

  return undirected;
}

struct WeightedEdge {
  int dst;
  double weight;
};

using WeightedAdjacencyList = vector<vector<WeightedEdge>>;

inline void print(const WeightedAdjacencyList &graph) {
  for (int node = 0; node < graph.size(); ++node) {
    std::cout << node << std::endl;
    for (const auto &edge : graph[node]) {
      std::cout << "->" << edge.dst << ": " << edge.weight << std::endl;
    }
  }
}

template <typename Element> void print(const vector<Element> &vec) {
  std::cout << '[';
  for (const auto &element : vec) {
    std::cout << element << ',';
  }
  std::cout << ']';
}

#endif // GRAPH_TYPES_H_
