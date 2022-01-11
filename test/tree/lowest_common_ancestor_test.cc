#include "tree/lowest_common_ancestor.h"

#include <gtest/gtest.h>

#include "testing/testing.h"
#include "tree/root_tree.h"

TEST(LowestCommonAncestor, LinearGraph) {
  const AdjacencyList graph = makeUndirected({
      {1},
      {2},
      {3},
      {},
  });
  Tree* tree = rootTree(graph, 0);

  EXPECT_EQ(lowestCommonAncestor(tree, 2, 2), 2);
  EXPECT_EQ(lowestCommonAncestor(tree, 1, 3), 1);
  EXPECT_EQ(lowestCommonAncestor(tree, 3, 1), 1);
  EXPECT_EQ(lowestCommonAncestor(tree, 0, 3), 0);

  deleteTree(tree);
}

TEST(LowestCommonAncestor, FullGraph) {
  const AdjacencyList graph = makeUndirected({
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
  });
  Tree* tree = rootTree(graph, 0);

  EXPECT_EQ(lowestCommonAncestor(tree, 2, 3), 1);
  EXPECT_EQ(lowestCommonAncestor(tree, 2, 7), 0);
  EXPECT_EQ(lowestCommonAncestor(tree, 7, 9), 6);
  EXPECT_EQ(lowestCommonAncestor(tree, 1, 6), 0);

  deleteTree(tree);
}
