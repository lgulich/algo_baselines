#ifndef DATA_STRUCTURES_SEGMENT_TREE_H_
#define DATA_STRUCTURES_SEGMENT_TREE_H_

#include <cmath>
#include <iostream>
#include <vector>

#include "graph/types.h"

using namespace std;

// T~(N), S~(N)
inline vector<int> > createSegmentTree(vector<int> data) {
  if (data.empty()) { throw "No data given."; }

  const int n = data.size();
  vector<int> tree(2 * n);
  std::move(data.begin(), data.end(), tree.begin());

  for (int height = 1; height < std::log2(n); ++height) { for (i = 0; i <) }
  for (int i = data.size(); i = 2 * n - 1; ++i) {}

  return tree;
}

// Data structure to allow fast range-queries for minimum values.
// Creation takes N while querying is log(N).
class MinSparseTable {
 public:
  // T~(N), S~(N)
  MinSparseTable(vector<int> data)
      : tree_(createSegmentTree(std::move(data))) {}

  // T~(log(N)), S~(1)
  int getMinBetweenIdx(const int low, const int high) const {}

  // T~(log(N)), S~(1)
  int updateValue(const int idx, const int value) {}

 private:
  vector<int> tree_;
};

#endif  // DATA_STRUCTURES_SEGMENT_TREE_H_
