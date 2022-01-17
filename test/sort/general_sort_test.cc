#include <gtest/gtest.h>

#include "sort/merge_sort.h"
#include "sort/quick_sort.h"
#include "sort/selection_sort.h"
#include "testing/testing.h"

using SortFunction = void (*)(vector<int>*);

class GeneralSortingTests : public testing::TestWithParam<SortFunction> {};

TEST_P(GeneralSortingTests, SortEmptyVector) {
  const auto sort = GetParam();
  vector<int> data{};
  sort(&data);
  expect_eq(data, {});
}

TEST_P(GeneralSortingTests, SortOneElement) {
  const auto sort = GetParam();
  vector<int> data{1};
  sort(&data);
  expect_eq(data, {1});
}

TEST_P(GeneralSortingTests, SortTwoElement) {
  const auto sort = GetParam();
  vector<int> data{2, 1};
  sort(&data);
  expect_eq(data, {1, 2});
}

TEST_P(GeneralSortingTests, SortThreeElement) {
  const auto sort = GetParam();
  vector<int> data{2, 1, 3};
  sort(&data);
  expect_eq(data, {1, 2, 3});
}

TEST_P(GeneralSortingTests, ReverseSortedVector) {
  const auto sort = GetParam();
  vector<int> data{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  sort(&data);
  expect_eq(data, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
}

TEST_P(GeneralSortingTests, RandomVector) {
  const auto sort = GetParam();
  vector<int> data{9, 0, 8, 1, 7, 2, 6, 3, 5, 4};
  sort(&data);
  expect_eq(data, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
}

INSTANTIATE_TEST_SUITE_P(
    MergeSort, GeneralSortingTests, testing::Values(&mergeSort));
INSTANTIATE_TEST_SUITE_P(
    SelectionSort, GeneralSortingTests, testing::Values(&selectionSort));
INSTANTIATE_TEST_SUITE_P(
    QuickSort, GeneralSortingTests, testing::Values(&quickSort));
