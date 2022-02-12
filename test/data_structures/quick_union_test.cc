#include "data_structures/quick_union.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(QuickUnion, FullVector) {
  QuickUnion data(10);
  data.connect(0,1);
  data.connect(2,3);
  data.connect(4,5);
  data.connect(6,7);
  data.connect(8,9);

  EXPECT_EQ(data.isConnected(0, 1), true);
  EXPECT_EQ(data.isConnected(4, 5), true);
  EXPECT_EQ(data.isConnected(1, 2), false);

  data.connect(1,6);
  EXPECT_EQ(data.isConnected(1, 6), true);
  EXPECT_EQ(data.isConnected(0, 7), true);
  EXPECT_EQ(data.isConnected(1, 5), false);

  data.connect(2,4);
  EXPECT_EQ(data.isConnected(2, 4), true);
  EXPECT_EQ(data.isConnected(3, 5), true);
  EXPECT_EQ(data.isConnected(1, 2), false);

  data.connect(0,5);
  EXPECT_EQ(data.isConnected(0, 5), true);
  EXPECT_EQ(data.isConnected(7, 2), true);
  EXPECT_EQ(data.isConnected(4, 6), true);
  EXPECT_EQ(data.isConnected(3, 8), false);

  data.connect(4,8);
  EXPECT_EQ(data.isConnected(0, 1), true);
  EXPECT_EQ(data.isConnected(1, 2), true);
  EXPECT_EQ(data.isConnected(2, 3), true);
  EXPECT_EQ(data.isConnected(3, 4), true);
  EXPECT_EQ(data.isConnected(4, 5), true);
  EXPECT_EQ(data.isConnected(5, 6), true);
  EXPECT_EQ(data.isConnected(6, 7), true);
  EXPECT_EQ(data.isConnected(7, 8), true);
  EXPECT_EQ(data.isConnected(8, 9), true);
  EXPECT_EQ(data.isConnected(9, 0), true);
}

