#include "data_structures/binary_search_tree.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(BinarySearchTree, FullBst) {
  BinarySearchTree tree;
  EXPECT_EQ(tree.size(), 0);

  tree.insert(7);
  tree.insert(3);
  tree.insert(8);
  tree.insert(1);
  tree.insert(10);
  EXPECT_EQ(tree.size(), 5);

  EXPECT_EQ(tree.findLess(6), 3);
  EXPECT_EQ(tree.findLess(7), 3);
  EXPECT_THROW(tree.findLess(1), const char*);

  EXPECT_EQ(tree.findLessOrEqual(6), 3);
  EXPECT_EQ(tree.findLessOrEqual(7), 7);
  EXPECT_EQ(tree.findLessOrEqual(1), 1);
  EXPECT_THROW(tree.findLessOrEqual(0), const char*);

  EXPECT_EQ(tree.findGreater(4), 7);
  EXPECT_EQ(tree.findGreater(3), 7);
  EXPECT_THROW(tree.findGreater(10), const char*);

  EXPECT_EQ(tree.findGreaterOrEqual(4), 7);
  EXPECT_EQ(tree.findGreaterOrEqual(3), 3);
  EXPECT_EQ(tree.findGreaterOrEqual(10), 10);
  EXPECT_THROW(tree.findGreaterOrEqual(11), const char*);

  EXPECT_EQ(tree.countInRange(3, 8), 3);
  EXPECT_EQ(tree.countInRange(2, 9), 3);
  EXPECT_EQ(tree.countInRange(1, 8), 4);
  EXPECT_EQ(tree.countInRange(0, 8), 4);
  EXPECT_EQ(tree.countInRange(7, 10), 3);
  EXPECT_EQ(tree.countInRange(7, 11), 3);
  EXPECT_EQ(tree.countInRange(0, 11), 5);
}
