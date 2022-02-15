#ifndef _USERS_LIONELGULICH_DOCUMENTS_CODE_LEARN_ALGO_BASELINES_TEST_SEARCH_RANGE_CONTAINS_TEST_CC_RANGE_CONTAINS_TEST_CC_
#define _USERS_LIONELGULICH_DOCUMENTS_CODE_LEARN_ALGO_BASELINES_TEST_SEARCH_RANGE_CONTAINS_TEST_CC_RANGE_CONTAINS_TEST_CC_

#include "search/range_contains.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(RangeContains, EmptyRange) {
  const vector<vector<int>> ranges{};
  EXPECT_FALSE(contains(ranges, 0));
}

TEST(RangeContains, SingleRange) {
  const vector<vector<int>> ranges{{2, 4}};
  EXPECT_FALSE(contains(ranges, 1));
  EXPECT_TRUE(contains(ranges, 2));
  EXPECT_TRUE(contains(ranges, 3));
  EXPECT_TRUE(contains(ranges, 4));
  EXPECT_FALSE(contains(ranges, 5));
}

TEST(RangeContains, TwoRanges) {
  const vector<vector<int>> ranges{{2, 4}, {6, 8}};
  EXPECT_FALSE(contains(ranges, 1));
  EXPECT_TRUE(contains(ranges, 2));
  EXPECT_TRUE(contains(ranges, 3));
  EXPECT_TRUE(contains(ranges, 4));
  EXPECT_FALSE(contains(ranges, 5));
  EXPECT_TRUE(contains(ranges, 6));
  EXPECT_TRUE(contains(ranges, 7));
  EXPECT_TRUE(contains(ranges, 8));
  EXPECT_FALSE(contains(ranges, 9));
}

TEST(RangeContains, MultipleRanges) {
  const vector<vector<int>> ranges{
      {2, 4}, {6, 8}, {12, 22}, {23, 28}, {101, 110}};
  EXPECT_FALSE(contains(ranges, 1));
  EXPECT_FALSE(contains(ranges, 5));
  EXPECT_FALSE(contains(ranges, 9));
  EXPECT_FALSE(contains(ranges, 44));
  EXPECT_FALSE(contains(ranges, 112));

  EXPECT_TRUE(contains(ranges, 3));
  EXPECT_TRUE(contains(ranges, 7));
  EXPECT_TRUE(contains(ranges, 18));
  EXPECT_TRUE(contains(ranges, 27));
  EXPECT_TRUE(contains(ranges, 108));
}

#endif  // _USERS_LIONELGULICH_DOCUMENTS_CODE_LEARN_ALGO_BASELINES_TEST_SEARCH_RANGE_CONTAINS_TEST_CC_RANGE_CONTAINS_TEST_CC_
