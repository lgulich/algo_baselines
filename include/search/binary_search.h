#ifndef SEARCH_BINARY_SEARCH_H_
#define SEARCH_BINARY_SEARCH_H_

#include <vector>

using namespace std;

// T~O(log(N)), S~O(1)
inline int binarySearchIdx(const vector<int>& data, const int value) {
  int left = 0;
  int right = data.size();

  while (true) {
    // We look in an empty subset, thus the value does not exist:
    if (left == right) { return -1; }

    const int middle = left + (right - left) / 2;
    // We found the value:
    if (data[middle] == value) { return middle; }

    if (data[middle] < value) {
      left = middle + 1;
    } else {
      right = middle;
    }
  }
}

#endif  // SEARCH_BINARY_SEARCH_H_
