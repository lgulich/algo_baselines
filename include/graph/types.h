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

#endif // GRAPH_TYPES_H_
