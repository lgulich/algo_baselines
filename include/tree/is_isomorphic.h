#ifndef TREE_IS_ISOMORPHIC_H_
#define TREE_IS_ISOMORPHIC_H_

#include "graph/types.h"
#include "tree/find_center.h"
#include "tree/hash_tree.h"
#include "tree/root_tree.h"
#include "tree/types.h"

// Determine if two trees are isomorphic, i.e. have the same topology.
// T~(N*log(N)), S~(N)
inline bool isIsomorphic(const AdjacencyList& a, const AdjacencyList& b) {
  if(a.empty() && b.empty()){return true;}

  const vector<int> centers_a = findCenter(a);
  const vector<int> centers_b = findCenter(b);

  if (centers_a.size() != centers_b.size()) {
    return false;
  }

  for (const int center_a : centers_a) {
    const Tree* tree_a = rootTree(a, center_a);
    const string hash_a = hashTree(tree_a);
    for (const int center_b : centers_b) {
      const Tree* tree_b = rootTree(a, center_a);
      const string hash_b = hashTree(tree_b);

      if (hash_a == hash_b) {
        return true;
      }
    }
  }

  return false;
}

#endif  // TREE_IS_ISOMORPHIC_H_
