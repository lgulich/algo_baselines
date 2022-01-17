#ifndef SORT_MERGE_SORT_H_
#define SORT_MERGE_SORT_H_

#include <vector>

#include "util/stl_print.h"

using namespace std;

inline void merge(
    const vector<int>::iterator begin, const vector<int>::iterator middle,
    const vector<int>::iterator end) {
  auto a = begin;
  auto b = middle;

  vector<int> res;
  res.reserve(end - begin);

  while (true) {
    if (a == middle && b == end) {
      break;
    } else if (a == middle) {
      res.push_back(*b);
      ++b;
    } else if (b == end) {
      res.push_back(*a);
      ++a;
    } else {
      if (*a < *b) {
        res.push_back(*a);
        ++a;
      } else {
        res.push_back(*b);
        ++b;
      }
    }
  }

  std::move(res.begin(), res.end(), begin);
}

inline void mergeSortRecursive(
    const vector<int>::iterator begin, const vector<int>::iterator end) {
  // Vectors of size 0 and 1 are already sorted thus we stop.
  if (end - begin <= 1) { return; }

  // Sort both splits.
  const auto middle = begin + (end - begin) / 2;

  mergeSortRecursive(begin, middle);
  mergeSortRecursive(middle, end);

  // Merge the splits together.
  merge(begin, middle, end);
}

// Sort array by recursively splitting array in half and merge sorted halfs.
// T~O(N*log(N)), S~O(N)
inline void mergeSort(vector<int>* data) {
  mergeSortRecursive(data->begin(), data->end());
}

#endif  // SORT_MERGE_SORT_H_
