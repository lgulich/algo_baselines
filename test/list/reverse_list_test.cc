#include "list/reverse_list.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(ListType, ListCreationWorks) {
  List* list = createList({0, 1, 2, 3, 4});
  expect_eq(list, {0, 1, 2, 3, 4});
  deleteList(list);
}

TEST(ReverseList, EmptyList) {
  List* list = nullptr;
  list = reverseList(list);
  expect_eq(list, {});
}

TEST(ReverseList, SingleNodeList) {
  List* list = createList({1});
  list = reverseList(list);
  expect_eq(list, {1});
  deleteList(list);
}

TEST(ReverseList, TwoNodeList) {
  List* list = createList({1, 2});
  list = reverseList(list);
  expect_eq(list, {2, 1});
  deleteList(list);
}

TEST(ReverseList, LongList) {
  List* list = createList({1, 2, 3, 4, 5, 6, 7, 8, 9});
  list = reverseList(list);
  expect_eq(list, {9, 8, 7, 6, 5, 4, 3, 2, 1});
  deleteList(list);
}
