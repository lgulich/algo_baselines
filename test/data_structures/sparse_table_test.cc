#include "data_structures/sparse_table.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

// TEST(SparseTable, EmptyVector) {
//   EXPECT_THROW(const MinSparseTable table({}), const char*);
// }

// TEST(SparseTable, SingleElement) {
//   const MinSparseTable table({1});
//   EXPECT_EQ(table.getMinBetweenIdx(0, 0), 1);
//   EXPECT_THROW(table.getMinBetweenIdx(0, 1), const char*);
// }

// TEST(SparseTable, TwoElements) {
//   const MinSparseTable table({5, 3});
//   EXPECT_EQ(table.getMinBetweenIdx(0, 0), 5);
//   EXPECT_EQ(table.getMinBetweenIdx(0, 1), 3);
//   EXPECT_THROW(table.getMinBetweenIdx(0, 4), const char*);
// }

TEST(SparseTable, GeneralVector) {
  const MinSparseTable table({4, -3, 2, 19, -7, 9});
  EXPECT_EQ(table.getMinBetweenIdx(0, 5), -7);
  EXPECT_EQ(table.getMinBetweenIdx(1, 3), -3);
  EXPECT_EQ(table.getMinBetweenIdx(3, 5), -7);
}
