#include "graph/topological_sort.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(TopologicalSortDfs, EmptyGraph) {
  const AdjacencyList graph;
  const vector<int> order = topologicalSortDfs(graph);
  expect_eq(order, {});
}

TEST(TopologicalSortDfs, LinearGraph) {
  const AdjacencyList graph{
      {1},
      {2},
      {3},
      {},
  };

  const vector<int> order = topologicalSortDfs(graph);
  expect_eq(order, {0, 1, 2, 3});
  expect_topological_order(order, graph);
}

TEST(TopologicalSortDfs, FullGraph) {
  const AdjacencyList graph{
      {3},       // 0
      {3},       // 1
      {0, 1},    // 2
      {6, 7},    // 3
      {0, 3, 5}, // 4
      {9, 10},   // 5
      {8},       // 6
      {8, 9},    // 7
      {11},      // 8
      {11, 12},  // 9
      {9},       // 10
      {},        // 11
      {},        // 12
  };

  const vector<int> order = topologicalSortDfs(graph);
  expect_topological_order(order, graph);
}
TEST(TopologicalSortKahn, EmptyGraph) {
  const AdjacencyList graph;
  const vector<int> order = topologicalSortKahn(graph);
  expect_eq(order, {});
}

TEST(TopologicalSortKahn, LinearGraph) {
  const AdjacencyList graph{
      {1},
      {2},
      {3},
      {},
  };

  const vector<int> order = topologicalSortKahn(graph);
  expect_eq(order, {0, 1, 2, 3});
  expect_topological_order(order, graph);
}

TEST(TopologicalSortKahn, FullGraph) {
  const AdjacencyList graph{
      {3},       // 0
      {3},       // 1
      {0, 1},    // 2
      {6, 7},    // 3
      {0, 3, 5}, // 4
      {9, 10},   // 5
      {8},       // 6
      {8, 9},    // 7
      {11},      // 8
      {11, 12},  // 9
      {9},       // 10
      {},        // 11
      {},        // 12
  };

  const vector<int> order = topologicalSortKahn(graph);
  expect_topological_order(order, graph);
}

TEST(TopologicalSortKahn, LoopGraph) {
  const AdjacencyList graph{
      {}, {}, {0, 3}, {1, 6}, {0}, {2}, {5, 7}, {4},
  };

  EXPECT_THROW(topologicalSortKahn(graph), const char *);
}
