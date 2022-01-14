#include "search/binary_search.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(BinarySearch, EmptyVector) {
  const vector<int> data{};
  EXPECT_EQ(binarySearchIdx(data, 0), -1);
}

TEST(BinarySearch, SingleElement) {
  const vector<int> data{0};
  EXPECT_EQ(binarySearchIdx(data, 0), 0);
  EXPECT_EQ(binarySearchIdx(data, 1), -1);
}

TEST(BinarySearch, TwoElements) {
  const vector<int> data {0,1};
  EXPECT_EQ(binarySearchIdx(data, -1),-1);
  EXPECT_EQ(binarySearchIdx(data, 0),0);
  EXPECT_EQ(binarySearchIdx(data, 1), 1);
  EXPECT_EQ(binarySearchIdx(data, 2),-1);
}

TEST(BinarySearch, EvenNumberOfElements) {
  const vector<int> data {0,1,2,3,4,5};
  EXPECT_EQ(binarySearchIdx(data, -1), -1);
  EXPECT_EQ(binarySearchIdx(data, 0), 0);
  EXPECT_EQ(binarySearchIdx(data, 1), 1);
  EXPECT_EQ(binarySearchIdx(data, 2), 2);
  EXPECT_EQ(binarySearchIdx(data, 3), 3);
  EXPECT_EQ(binarySearchIdx(data, 4), 4);
  EXPECT_EQ(binarySearchIdx(data, 5), 5);
  EXPECT_EQ(binarySearchIdx(data, 6), -1);
}

TEST(BinarySearch, OddNumberOfElements) {
  const vector<int> data {0,1,2,3,4,5,6};
  EXPECT_EQ(binarySearchIdx(data, -1), -1);
  EXPECT_EQ(binarySearchIdx(data, 0), 0);
  EXPECT_EQ(binarySearchIdx(data, 1), 1);
  EXPECT_EQ(binarySearchIdx(data, 2), 2);
  EXPECT_EQ(binarySearchIdx(data, 3), 3);
  EXPECT_EQ(binarySearchIdx(data, 4), 4);
  EXPECT_EQ(binarySearchIdx(data, 5), 5);
  EXPECT_EQ(binarySearchIdx(data, 6), 6);
  EXPECT_EQ(binarySearchIdx(data, 7), -1);
}
