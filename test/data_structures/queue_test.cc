#include "data_structures/queue.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(Queue, EmptyVector) {
  Queue queue;
  EXPECT_EQ(queue.size(), 0);

  queue.push(1);
  EXPECT_EQ(queue.size(), 1);
  EXPECT_EQ(queue.front(), 1);

  queue.push(2);
  EXPECT_EQ(queue.size(), 2);
  EXPECT_EQ(queue.front(), 1);
  expect_eq(static_cast<vector<int>>(queue), {1, 2});

  queue.pop();
  EXPECT_EQ(queue.size(), 1);
  EXPECT_EQ(queue.front(), 2);

  queue.pop();
  EXPECT_EQ(queue.size(), 0);
  EXPECT_THROW(queue.front(), const char*);
  EXPECT_THROW(queue.pop(), const char*);
}
