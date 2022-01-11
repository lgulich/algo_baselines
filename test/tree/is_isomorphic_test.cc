#include "tree/is_isomorphic.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(IsIsomorphic, EmptyGraph) {
  const AdjacencyList a;
  const AdjacencyList b;
  const AdjacencyList c = makeUndirected({{1}, {}});

  EXPECT_TRUE(isIsomorphic(a, b));
  EXPECT_FALSE(isIsomorphic(a, c));
}

TEST(IsIsomorphic, LinearGraph) {
  const AdjacencyList a = makeUndirected({
      {1},
      {2},
      {3},
      {},
  });
  const AdjacencyList b = makeUndirected({
      {3},
      {},
      {1},
      {2},
  });
  const AdjacencyList c = makeUndirected({
      {1},
      {2},
      {3},
      {4},
      {},
  });

  EXPECT_TRUE(isIsomorphic(a, b));
  EXPECT_FALSE(isIsomorphic(a, c));
}

TEST(IsIsomorphic, FullGraph) {
  const AdjacencyList a = makeUndirected({
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
  const AdjacencyList b = makeUndirected({
      {},         // 0
      {},         // 1
      {},         // 2
      {0, 1, 2},  // 3
      {3},        // 4
      {},         // 5
      {7, 8},     // 6
      {},         // 7
      {},         // 8
      {6, 4, 5},  // 9
  });
  const AdjacencyList c = makeUndirected({
      {},         // 0
      {},         // 1
      {},         // 2
      {0, 1, 2},  // 3
      {},         // 4
      {4},        // 5
      {7, 8},     // 6
      {},         // 7
      {},         // 8
      {6, 3, 5},  // 9
  });

  EXPECT_TRUE(isIsomorphic(a, a));
  EXPECT_TRUE(isIsomorphic(a, b));
  EXPECT_FALSE(isIsomorphic(a, c));
}
