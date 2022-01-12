#include "dynamic_programming/mountain_scenes.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(MountainScenes, RecursiveImplementation) {
  EXPECT_EQ(numMountainScenesRecursive(4, 2, 2), 6);
  EXPECT_EQ(numMountainScenesRecursive(10, 10, 1), 1022);
  EXPECT_EQ(numMountainScenesRecursive(15, 5, 5), 6050);
  EXPECT_EQ(numMountainScenesRecursive(25, 5, 5), 7770);
}

TEST(MountainScenes, IterativeImplementation) {
  EXPECT_EQ(numMountainScenesIterative(4, 2, 2), 6);
  EXPECT_EQ(numMountainScenesIterative(10, 10, 1), 1022);
  EXPECT_EQ(numMountainScenesIterative(15, 5, 5), 6050);
  EXPECT_EQ(numMountainScenesIterative(25, 5, 5), 7770);
}
