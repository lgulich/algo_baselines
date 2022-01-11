#include "search/search_pattern_kmp.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(KmpCount, PrefixCreation) {
  const vector<int> prefix =
      createPrefixArray({0, 1, 2, 0, 1, 3, 0, 1, 2, 0, 1, 2, 0});
  expect_eq(prefix, {-1, -1, -1, 0, 1, -1, 0, 1, 2, 3, 4, 2, 3});
}

TEST(Kmp, GeneralVector) {
  const vector<int> data{1, 2, 4, 1, 2, 5, 1, 2, 3, 1,
                         2, 5, 6, 1, 2, 5, 1, 2, 7};
  const vector<int> existing_pattern{1, 2, 3};
  const vector<int> non_existing_pattern{1, 2, 9};
  EXPECT_TRUE(searchPatternKmp(data, {1, 2, 3}));
  EXPECT_TRUE(searchPatternKmp(data, {1, 2, 3, 1, 2}));
  EXPECT_FALSE(searchPatternKmp(data, {1, 2, 9}));
  EXPECT_FALSE(searchPatternKmp(data, {1, 2, 3, 1, 2, 6}));
}
