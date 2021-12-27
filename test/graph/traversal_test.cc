#include "graph/traversal.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(BfsTraversal, EmptyGraph) {
  const AdjacencyList graph;
  const vector<int> order = bfsTraversal(graph, 0);
  expect_eq(order, {});
}

TEST(BfsTraversal, LinearGraph) {
  const AdjacencyList graph{
      {1},
      {2},
      {3},
      {},
  };

  const vector<int> order = bfsTraversal(graph, 0);
  expect_eq(order, {0, 1, 2, 3});
}

TEST(BfsTraversal, FullGraph) {
  const AdjacencyList graph{
      {}, {}, {0, 3}, {1, 6}, {0}, {2}, {5, 7}, {4},
  };

  const vector<int> order = bfsTraversal(graph, 6);

  expect_eq(order, {6, 5, 7, 2, 4, 0, 3, 1});
}

TEST(DfsTraversal, EmptyGraph) {
  const AdjacencyList graph;
  const vector<int> order = dfsTraversal(graph, 0);
  expect_eq(order, {});
}

TEST(DfsTraversal, LinearGraph) {
  const AdjacencyList graph{
      {1},
      {2},
      {3},
      {},
  };

  const vector<int> order = dfsTraversal(graph, 0);
  expect_eq(order, {0, 1, 2, 3});
}

TEST(DfsTraversal, FullGraph) {
  const AdjacencyList graph{
      {}, {}, {0, 3}, {1, 6}, {0}, {2}, {5, 7}, {4},
  };

  const vector<int> order = dfsTraversal(graph, 6);
  expect_eq(order, {6, 7, 4, 0, 5, 2, 3, 1});
}
