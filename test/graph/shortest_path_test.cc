#include "graph/shortest_path.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

constexpr double kInf = std::numeric_limits<double>::infinity();

TEST(ShortestPathBellford, EmptyGraph) {
  const WeightedAdjacencyList graph;
  const vector<double> costs = shortestPathBellford(graph, 0);
  expect_eq(costs, {});
}

TEST(ShortestPathBellford, LinearGraph) {
  const WeightedAdjacencyList graph{
      {{1, 1.0}},
      {{2, 2.0}},
      {{3, 3.0}},
      {},
  };

  const vector<double> costs = shortestPathBellford(graph, 0);
  expect_eq(costs, {0., 1., 3., 6.});
}

TEST(ShortestPathBellford, StartNodeNotInGraph) {
  const WeightedAdjacencyList graph{
      {{1, 1.0}},
      {{2, 2.0}},
      {{3, 3.0}},
      {},
  };

  const vector<double> costs = shortestPathBellford(graph, 4);
  expect_eq(costs, {kInf, kInf, kInf, kInf});
}

TEST(ShortestPathBellford, FullGraph) {
  const WeightedAdjacencyList graph{
      {{1, 1.}, {2, 1.}, {7, 2.}},  // 0
      {{3, 4.}},                    // 1
      {{1, 1.}},                    // 2
      {{2, -6}, {4, 1.}, {5, 1.}},  // 3
      {{5, 1.}, {6, 1.}},           // 4
      {{6, 1.}},                    // 5
      {},                           // 6
      {},                           // 7
  };

  const vector<double> costs = shortestPathBellford(graph, 0);
  expect_eq(costs, {0., -kInf, -kInf, -kInf, -kInf, -kInf, -kInf, 2.});
}

TEST(ShortestPathDijkstra, EmptyGraph) {
  const WeightedAdjacencyList graph;
  const vector<int> path = shortestPathDijkstra(graph, 0, 1);
  expect_eq(path, {});
}

TEST(ShortestPathDijkstra, LinearGraph) {
  const WeightedAdjacencyList graph{
      {{1, 1.0}},
      {{2, 2.0}},
      {{3, 3.0}},
      {},
  };

  const vector<int> path = shortestPathDijkstra(graph, 0, 3);
  expect_eq(path, {0, 1, 2, 3});
}

TEST(ShortestPathDijkstra, StartNodeNotInGraph) {
  const WeightedAdjacencyList graph{
      {{1, 1.0}},
      {{2, 2.0}},
      {{3, 3.0}},
      {},
  };

  const vector<int> path = shortestPathDijkstra(graph, 4, 2);
  expect_eq(path, {});
}

TEST(ShortestPathDijkstra, FullGraph) {
  const WeightedAdjacencyList graph{
      {{1, 1.}, {2, 2.}},  // 0
      {{3, 1.}},           // 1
      {{3, 1.}},           // 2
      {{4, 1}, {5, 1.}},   // 3
      {{6, 2.}},           // 4
      {{6, 1.}},           // 5
      {},                  // 6
  };

  const vector<int> path = shortestPathDijkstra(graph, 0, 6);
  expect_eq(path, {0, 1, 3, 5, 6});
}

TEST(ShortestPathDijkstra, PathNotExisting) {
  const WeightedAdjacencyList graph{
      {{1, 1.}},  // 0
      {{2, 2.}},  // 1
      {{3, 3.}},  // 2
      {},         // 3
  };

  const vector<int> path = shortestPathDijkstra(graph, 3, 0);
  expect_eq(path, {});
}
