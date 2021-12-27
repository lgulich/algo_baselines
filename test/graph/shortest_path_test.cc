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
  print(costs);
  expect_eq(costs, {0., -kInf, -kInf, -kInf, -kInf, -kInf, -kInf, 2.});
}
