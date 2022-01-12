#ifndef DYNAMIC_PROGRAMMING_NARROW_ART_GALLERY_H_
#define DYNAMIC_PROGRAMMING_NARROW_ART_GALLERY_H_

#include <algorithm>
#include <cmath>
#include <vector>

// Problem described here:
// https://open.kattis.com/problems/narrowartgallery

using namespace std;

int maxValue(
    const int n, const int k, const int s, const vector<vector<int>>& rooms) {
  // We have an empty gallery.
  if (n == -1) {
    if (k == 0) {
      return 0;
    } else {
      return -1;
    }
  }

  // We have already closed all needed rooms.
  if (k == 0) {
    const int res = rooms[n][0] + rooms[n][1] + maxValue(n - 1, k, 0, rooms);
    return res;
  }

  // We are in the middle of the gallery and still need to close rooms.
  vector<int> options;
  options.reserve(3);

  // Close nothing
  const int close_nothing_recursion = maxValue(n - 1, k, 0, rooms);
  if (close_nothing_recursion >= 0) {
    const int close_nothing =
        close_nothing_recursion + rooms[n][0] + rooms[n][1];
    options.push_back(close_nothing);
  }

  // We evaluate the option of closing the left room. We can only do this the
  // right room of the previous layer is not closed.
  if (s != 2) {
    const int recursion = maxValue(n - 1, k - 1, 1, rooms);
    if (recursion >= 0) {
      const int close_left = recursion + rooms[n][1];
      options.push_back(close_left);
    }
  }

  // We evaluate the option of closing the right room. We can only do this if
  // the left room of the previous layer is not closed.
  if (s != 1) {
    const int recursion = maxValue(n - 1, k - 1, 2, rooms);
    if (recursion >= 0) {
      const int close_right = recursion + rooms[n][0];
      options.push_back(close_right);
    }
  }
  const int res = *std::max_element(options.begin(), options.end());
  return res;
}

// If memoization is added the complexity becomes:
// T~O(k*N), S~O(k*N)
int maxGalleryValue(const int k, const vector<vector<int>>& rooms) {
  return maxValue(rooms.size() - 1, k, 0, rooms);
}

#endif  // DYNAMIC_PROGRAMMING_NARROW_ART_GALLERY_H_
