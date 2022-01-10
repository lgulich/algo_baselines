#include "tree/find_center.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(FindCenter, EmptyGraph) {
  const AdjacencyList graph;
  const vector<int> center = findCenter(graph);
  expect_eq(center, {});
}

TEST(FindCenter, SingleNodeGraph) {
  const AdjacencyList directed{
      {},
  };
  const AdjacencyList undirected = makeUndirected(directed);
  const vector<int> center = findCenter(undirected);
  expect_eq(center, {0});
}

TEST(FindCenter, TwoNodeGraph) {
  const AdjacencyList directed{{1}, {}};
  const AdjacencyList undirected = makeUndirected(directed);
  const vector<int> center = findCenter(undirected);
  expect_eq(center, {0, 1});
}

TEST(FindCenter, LinearGraph) {
  const AdjacencyList directed{
      {1},
      {2},
      {3},
      {},
  };
  const AdjacencyList undirected = makeUndirected(directed);
  const vector<int> center = findCenter(undirected);
  expect_eq(center, {1, 2});
}

TEST(FindCenter, FullGraph) {
  const AdjacencyList directed{
      {1},     // 0
      {3, 4},  // 1
      {3},     // 2
      {6, 7},  // 3
      {5, 8},  // 4
      {},      // 5
      {9},     // 6
      {},      // 7
      {},      // 8
      {},      // 9
  };
  const AdjacencyList undirected = makeUndirected(directed);
  const vector<int> center = findCenter(undirected);
  expect_eq(center, {1, 3});
}
