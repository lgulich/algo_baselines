#ifndef SEARCH_SEARCH_SMALLER_ELEMENT_H_
#define SEARCH_SEARCH_SMALLER_ELEMENT_H_

#include <vector>

using namespace std;

struct Index {
  int value;
  int offset;
};

// T~O(log(N)), S~O(1)
inline int searchSmallerElement(const vector<int>& data, const int value) {
  if (data.empty()) { return -1; }
  if (value < data.front()) { return -1; }
  if (data.back() < value) { return data.back(); }

  int left = 0;
  int right = data.size();
  int res = -1;

  while (left < right) {
    const int middle = left + (right - left) / 2;

    if (data[middle] == value) {
      return value;
    } else if (data[middle] < value) {
      res = data[middle];
      left = middle + 1;
    } else {
      right = middle;
    }
  }

  return res;
}

#endif  // SEARCH_SEARCH_SMALLER_ELEMENT_H_
