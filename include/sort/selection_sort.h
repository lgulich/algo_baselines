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


// Sort by finding smallest value and putting it at first position, then repeat
// with right hand side.
// T~O(N^2), S~O(1)
inline void selectionSort(vector<int>* data) {
  for (int i = 0; i < data->size(); ++i) {
    putMinToBegin(data->begin() + i, data->end());
  }
}

#endif  // SORT_SELECTION_SORT_H_
