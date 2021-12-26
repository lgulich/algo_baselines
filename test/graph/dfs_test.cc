#include <gtest/gtest.h>

#include "graph/dfs.h"

template <typename Element>
void expect_eq(const vector<Element>& a, const vector<Element>& b) {
  EXPECT_EQ(a.size(), b.size());

  for (int i = 0; i < a.size(); ++i) {
    EXPECT_EQ(a[i], b[i]);
  }
}

TEST(Dfs, EmptyGraph) {
  AdjacencyList graph;
  const vector<int> order = dfsOrder(graph, 0);
  expect_eq(order, {});
}

TEST(Dfs, LinearGraph) {
  AdjacencyList graph{
      {1},
      {2},
      {3},
      {},
  };

  const vector<int> order = dfsOrder(graph, 0);
  expect_eq(order, {0, 1, 2, 3});
}

TEST(Dfs, FullGraph) {
  AdjacencyList graph{
      {}, {}, {0, 3}, {1, 6}, {0}, {2}, {5, 7}, {4},
  };

  const vector<int> order = dfsOrder(graph, 6);

  for(int o : order){std::cout << o << ',';}
  std::cout << std::endl;
  expect_eq(order, {6, 7, 4, 0, 5, 2, 3, 1});
}
