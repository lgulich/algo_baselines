#include "tree/hash_tree.h"

#include <gtest/gtest.h>

#include "testing/testing.h"
#include "tree/root_tree.h"

TEST(HashTree, EmptyGraph) {
  const AdjacencyList graph;
  Tree* tree = rootTree(graph, 0);
  const string hash = hashTree(tree);
  EXPECT_EQ(hash, "");
  deleteTree(tree);
}

TEST(HashTree, LinearGraph) {
  const AdjacencyList directed_graph{
      {1},
      {2},
      {3},
      {},
  };
  const AdjacencyList undirected_graph = makeUndirected(directed_graph);
  Tree* tree = rootTree(undirected_graph, 0);

  const string hash = hashTree(tree);
  EXPECT_EQ(hash, "(((())))");

  deleteTree(tree);
}

TEST(HashTree, FullGraph) {
  const AdjacencyList directed_graph{
      {1, 4, 5},  // 0
      {2, 3},     // 1
      {},         // 2
      {},         // 3
      {},         // 4
      {6},        // 5
      {7, 8, 9},  // 6
      {},         // 7
      {},         // 8
      {},         // 9
  };
  const AdjacencyList undirected_graph = makeUndirected(directed_graph);
  Tree* tree = rootTree(undirected_graph, 0);

  const string hash = hashTree(tree);
  EXPECT_EQ(hash, "(((()()()))(()())())");
  deleteTree(tree);
}
