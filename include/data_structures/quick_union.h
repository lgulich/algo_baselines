#ifndef DATA_STRUCTURES_QUICK_UNION_H_
#define DATA_STRUCTURES_QUICK_UNION_H_

#include <numeric>
#include <vector>

using namespace std;

// Data structure that allows to connect nodes and efficiently check if two
// nodes are connected.
class QuickUnion {
 public:
  // T~O(N), S~O(N)
  explicit QuickUnion(const int num_nodes)
      : parent_(num_nodes), depth_(num_nodes, 1) {
    std::iota(parent_.begin(), parent_.end(), 0);
  }

  // T~O(log(N)), S~(1)
  void connect(const int a, const int b) {
    const int root_a = findRoot(a);
    const int root_b = findRoot(b);

    if (root_a == root_b) { return; }

    int& depth_root_a = depth_[root_a];
    int& depth_root_b = depth_[root_b];

    if (depth_root_a > depth_root_b) {
      parent_[root_b] = root_a;
    } else {
      parent_[root_a] = root_b;
      depth_root_b = max(depth_root_b, 1 + depth_root_a);
    }
  }

  // T~O(log(N)), S~(1)
  bool isConnected(const int a, const int b) const {
    return findRoot(a) == findRoot(b);
  }

 private:
  // T~O(log(N)), S~(1)
  int findRoot(int node) const {
    while (parent_[node] != node) { node = parent_[node]; }
    return node;
  }

  vector<int> parent_;
  vector<int> depth_;
};

#endif  // DATA_STRUCTURES_QUICK_UNION_H_
