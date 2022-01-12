#include "dynamic_programming/knapsack.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(Knapsack, NoCapacity) {
  const vector<int> weights{3, 4, 6, 5};
  const vector<int> values{2, 3, 1, 4};
  EXPECT_EQ(maxKnapsackValue(weights, values, 0), 0);
}

TEST(Knapsack, NoItems) {
  const vector<int> weights{};
  const vector<int> values{};
  EXPECT_EQ(maxKnapsackValue(weights, values, 0), 0);
}

TEST(Knapsack, CapacityIsBigEnoughForAllItems) {
  const vector<int> weights{3, 4, 6, 5};
  const vector<int> values{2, 3, 1, 4};
  EXPECT_EQ(maxKnapsackValue(weights, values, 100), 10);
}

TEST(Knapsack, GeneralCase) {
  const vector<int> weights{3, 4, 6, 5};
  const vector<int> values{2, 3, 1, 4};
  EXPECT_EQ(maxKnapsackValue(weights, values, 8), 6);
}
