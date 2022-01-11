#ifndef DATASTRUCTURES_SPARSE_TABLE_H_
#define DATASTRUCTURES_SPARSE_TABLE_H_

#include <cmath>
#include <iostream>
#include <vector>

#include "graph/types.h"

using namespace std;

// T~(N*log(N)), S~(N*log(N))
inline vector<vector<int>> createSparseTable(vector<int> data) {
  if (data.empty()) { throw "No data given."; }

  const int n = data.size();
  const int max_exp = std::floor(std::log2(n));

  vector<vector<int>> table(max_exp + 1, vector<int>(n));
  table[0] = std::move(data);

  int interval_length = 1;
  for (int row = 1; row <= max_exp; ++row) {
    interval_length *= 2;
    for (int col = 0; col < n - interval_length + 1; ++col) {
      table[row][col] = std::min(
          table[row - 1][col], table[row - 1][col + interval_length / 2]);
    }
  }

  return table;
}

// Data structure to allow fast range-queries for minimum values.
// Creation N*log(N) while querying is const time.
class MinSparseTable {
 public:
  // T~(N*log(N)), S~(N*log(N))
  MinSparseTable(vector<int> data)
      : table_(createSparseTable(std::move(data))) {}

  // T~(1), S~(1)
  int getMinBetweenIdx(const int low, const int high) const {
    const int interval_length = high - low + 1;
    if (interval_length < 0) { throw "Interval length is below 0"; }
    if (interval_length > table_.front().size()) { throw "Interval too long"; }

    const int max_exp = std::floor(std::log2(interval_length));
    const int max_length = std::pow(2, max_exp);

    const int lower_range_min = table_[max_exp][low];
    const int upper_range_min = table_[max_exp][high - max_length + 1];

    return std::min(lower_range_min, upper_range_min);
  }

 private:
  vector<vector<int>> table_;
};

#endif  // DATASTRUCTURES_SPARSE_TABLE_H_
