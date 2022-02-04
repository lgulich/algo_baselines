#ifndef SEARCH_QUICK_SELECT_H_
#define SEARCH_QUICK_SELECT_H_

#include <vector>
#include <iostream>

#include "sort/quick_sort.h"

using namespace std;

// Finds the k smallest value in a vector, puts it at index k-1 and partitions
// the array around it.
// T~O(N*log(N)), S~O(log(N))
inline void quickSelect(vector<int>* data, const int k) {
  if (k < 1 || k > data->size()) { throw "Invalid K"; }

  auto begin = data->begin();
  auto end = data->end();

  while (true) {
    const auto partition_it = partition(begin, end);
    const int partition_idx = partition_it - data->begin();

    if (partition_idx == k - 1) {
      return;
    } else if (partition_idx < k) {
      begin = partition_it + 1;
    } else {
      end = partition_it;
    }
  }
}

#endif  // SEARCH_QUICK_SELECT_H_
