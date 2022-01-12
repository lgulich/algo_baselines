#include "dynamic_programming/narrow_art_gallery.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(NarrowArtGallery, SingleRoom) {
  const vector<vector<int>> rooms{
      {7, 8},
  };
  EXPECT_EQ(maxGalleryValue(0, rooms), 15);
  EXPECT_EQ(maxGalleryValue(1, rooms), 8);
}

TEST(NarrowArtGallery, TwoRooms) {
  const vector<vector<int>> rooms{
      {7, 8},
      {4, 9},
  };
  EXPECT_EQ(maxGalleryValue(0, rooms), 28);
  EXPECT_EQ(maxGalleryValue(1, rooms), 24);
  EXPECT_EQ(maxGalleryValue(2, rooms), 17);
}

TEST(NarrowArtGallery, TwoRoomsAdjacent) {
  const vector<vector<int>> rooms{
      {7, 8},
      {9, 4},
  };
  EXPECT_EQ(maxGalleryValue(0, rooms), 28);
  EXPECT_EQ(maxGalleryValue(1, rooms), 24);
  EXPECT_EQ(maxGalleryValue(2, rooms), 16);
}

TEST(NarrowArtGallery, GeneralRoom) {
  const vector<vector<int>> rooms{
      {7, 8},  {4, 9},  {3, 7}, {5, 9}, {7, 2},
      {10, 3}, {0, 10}, {3, 2}, {6, 3}, {7, 9},
  };
  EXPECT_EQ(maxGalleryValue(5, rooms), 102);
}
