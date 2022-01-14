#include "search/search_smaller_element.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(SearchSmallerElement, EmptyVector) {
  const vector<int> data{};
  EXPECT_EQ(searchSmallerElement(data, 0), -1);
}

TEST(SearchSmallerElement, FullVector) {
  const vector<int> data{3, 4, 6, 9, 10, 12, 14, 15, 17, 19, 21};
  EXPECT_EQ(searchSmallerElement(data, 2), -1);
  EXPECT_EQ(searchSmallerElement(data, 3), 3);
  EXPECT_EQ(searchSmallerElement(data, 11), 10);
  EXPECT_EQ(searchSmallerElement(data, 12), 12);
  EXPECT_EQ(searchSmallerElement(data, 21), 21);
  EXPECT_EQ(searchSmallerElement(data, 22), 21);
}

