#include "sort/merge_sort.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(MergeSort, MergeEmptyVector) {
  vector<int> data{};
  merge(data.begin(), data.begin(), data.end());
  expect_eq(data, {});
}

TEST(MergeSort, MergeOneElement) {
  vector<int> data{1};
  merge(data.begin(), data.begin() +1, data.end());
  expect_eq(data, {1});
}

TEST(MergeSort, MergeTwoElement) {
  vector<int> data{2,1};
  merge(data.begin(), data.begin() +1, data.end());
  expect_eq(data, {1,2});
}

TEST(MergeSort, MergeEqualSize) {
  vector<int> data{2, 4, 5, 7, 8, /*split*/ 0, 1, 3, 6, 9};
  merge(data.begin(), data.begin() + 5, data.end());
  expect_eq(data, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
}

TEST(MergeSort, MergeUnequalSize) {
  vector<int> data{0, 1, 2, 4, 5, 7, 8, 9 /*split*/, 3, 6};
  merge(data.begin(), data.begin() + 8, data.end());
  expect_eq(data, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
}
