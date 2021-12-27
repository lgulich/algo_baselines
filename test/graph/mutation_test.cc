#include "graph/mutation.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(InvertAdjacencyList, EmptyGraph) {
  const AdjacencyList graph;
  const AdjacencyList inverted = invertAdjacencyList(graph);
  expect_eq(inverted, {});
}

TEST(InvertAdjacencyList, LinearGraph) {
  const AdjacencyList graph{
      {1},
      {2},
      {3},
      {},
  };

  const AdjacencyList inverted = invertAdjacencyList(graph);
  const AdjacencyList expected{{}, {0}, {1}, {2}};
  expect_eq(inverted, expected);
}

TEST(InvertAdjacencyList, FullGraph) {
  const AdjacencyList graph{
      {}, {}, {0, 3}, {1, 6}, {0}, {2}, {5, 7}, {4},
  };

  const AdjacencyList inverted = invertAdjacencyList(graph);
  const AdjacencyList expected{{2, 4}, {3}, {5}, {2}, {7}, {6}, {3} ,{6}};
  std::cout << "inverted\n";
  print(inverted);

  std::cout << "expected\n";
  print(expected);

  expect_eq(inverted, expected);
}

