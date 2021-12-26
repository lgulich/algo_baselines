#include <gtest/gtest.h>

#include "graph/bfs.h"

template <typename Element>
void expect_eq(const vector<Element>& a, const vector<Element>& b) {
  EXPECT_EQ(a.size(), b.size());

  for (int i = 0; i < a.size(); ++i) {
    EXPECT_EQ(a[i], b[i]);
  }
}

TEST(Bfs, EmptyGraph) {
  AdjacencyList graph;
  const vector<int> order = bfsOrder(graph, 0);
  expect_eq(order, {});
}

TEST(Bfs, LinearGraph) {
  AdjacencyList graph{
      {1},
      {2},
      {3},
      {},
  };

  const vector<int> order = bfsOrder(graph, 0);
  expect_eq(order, {0, 1, 2, 3});
}

TEST(Bfs, FullGraph) {
  AdjacencyList graph{
      {}, {}, {0, 3}, {1, 6}, {0}, {2}, {5, 7}, {4},
  };

  const vector<int> order = bfsOrder(graph, 6);

  expect_eq(order, {6, 5, 7, 2, 4, 0, 3, 1});
}
