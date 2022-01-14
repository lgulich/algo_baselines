#ifndef SORT_SELECTION_SORT_H_
#define SORT_SELECTION_SORT_H_

#include <algorithm>
#include <vector>

using namespace std;

inline void putMinToBegin(
    const vector<int>::iterator begin, const vector<int>::iterator end) {
  const auto min = std::min_element(begin, end);
  std::iter_swap(begin, min);
}

inline vector<int> selectionSort(const vector<int>& data) {
  vector<int> d = data;
  for (int i = 0; i < d.size(); ++i) { putMinToBegin(d.begin() + i, d.end()); }
  return d;
}

#endif  // SORT_SELECTION_SORT_H_
