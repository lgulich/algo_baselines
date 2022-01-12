#ifndef DYNAMIC_PROGRAMMING_KNAPSACK_H_
#define DYNAMIC_PROGRAMMING_KNAPSACK_H_

#include <vector>

using namespace std;

// Computes the maximum value of the goods which fit in the knapsack without
// exceeding its capacity limit.
// T~O(C*N), S~O(C*N)
int maxKnapsackValue(
    const vector<int>& weights, const vector<int>& values, const int capacity) {
  const int num_items = weights.size();
  if (num_items == 0) { return 0; }

  vector<vector<int>> max_value(capacity + 1, vector<int>(num_items+1, 0));

  for (int c = 1; c <= capacity; ++c) {
    for (int i = 1; i <= num_items; ++i) {
      const int weight_i = weights[i-1];
      const int value_i = values[i-1];

      if (weight_i > c) {
        max_value[c][i] = max_value[c][i - 1];
      } else {
        max_value[c][i] = max(
            max_value[c][i - 1], value_i + max_value[c - weight_i][i - 1]);
      }
    }
  }

  return max_value[capacity][num_items];
}

#endif  // DYNAMIC_PROGRAMMING_KNAPSACK_H_
