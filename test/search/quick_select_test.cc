#include "search/quick_select.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

void expectPartitioned(
    const vector<int>& data, const int k, const int partition) {
  EXPECT_EQ(data[k - 1],partition);
  for (int i = 0; i < k - 1; ++i) { EXPECT_LT(data[i], partition); }
  for (int i = k; i < data.size(); ++i) { EXPECT_GT(data[i], partition); }
}

TEST(QuickSelect, EmptyVector) {
   vector<int> data{};
  EXPECT_THROW(quickSelect(&data, 0), const char*);
}

TEST(QuickSelect, SingleElement) {
   vector<int> data{0};
  EXPECT_THROW(quickSelect(&data, 2), const char*);
  quickSelect(&data, 1);
  expectPartitioned(data, 1, 0);
}

TEST(QuickSelect, TwoElements) {
   vector<int> data{1,0};
  quickSelect(&data, 1);
  expectPartitioned(data, 1, 0);
  quickSelect(&data, 2);
  expectPartitioned(data, 2, 1);
}

TEST(QuickSelect, AllreadySorted) {
   vector<int> data{0,1,2,3,4,5};
  quickSelect(&data, 1);
  expectPartitioned(data, 1, 0);
  quickSelect(&data, 3);
  expectPartitioned(data, 3, 2);
  quickSelect(&data, 5);
  expectPartitioned(data, 6, 5);
}

TEST(QuickSelect, ReverseOrder) {
   vector<int> data{5,4,3,2,1,0};
  quickSelect(&data, 1);
  expectPartitioned(data, 1, 0);
  quickSelect(&data, 3);
  expectPartitioned(data, 3, 2);
  quickSelect(&data, 5);
  expectPartitioned(data, 6, 5);
}

TEST(QuickSelect, EvenNumberOfElements) {
   vector<int> data{5,2,3,0,4,1};
  quickSelect(&data, 1);
  expectPartitioned(data, 1, 0);
  quickSelect(&data, 3);
  expectPartitioned(data, 3, 2);
  quickSelect(&data, 6);
  expectPartitioned(data, 6, 5);
}

TEST(QuickSelect, OddNumberOfElements) {
   vector<int> data{5,2,6,3,0,4,1};
  quickSelect(&data, 1);
  expectPartitioned(data, 1, 0);
  quickSelect(&data, 3);
  expectPartitioned(data, 3, 2);
  quickSelect(&data, 5);
  expectPartitioned(data, 5, 4);
  quickSelect(&data, 7);
  expectPartitioned(data, 7, 6);
}
