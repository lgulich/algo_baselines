#ifndef SEARCH_RANGE_CONTAINS_H_
#define SEARCH_RANGE_CONTAINS_H_

#include <vector>

using namespace std;

bool contains(const vector<int>& range, const int value) {
  return value >= range.front() && value <= range.back();
}

bool contains(const vector<vector<int>>& ranges, const int value) {
  if (ranges.empty()) { return false; }

  if (value < ranges.front().front()) { return false; }
  if (value > ranges.back().back()) { return false; }

  int low = 0;
  int high = ranges.size();
  while (low < high) {
    const int middle = low + (high - low) / 2;
    const vector<int> middle_interval = ranges[middle];
    if (contains(middle_interval, value)) { return true; }
    if (value < middle_interval.front()) {
      high = middle;
    } else {
      low = middle + 1;
    }
  }
  return false;
}

#endif  // SEARCH_RANGE_CONTAINS_H_
