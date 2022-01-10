#ifndef TREE_HASH_TREE_H_
#define TREE_HASH_TREE_H_

#include <string>
#include <numeric>

#include "tree/types.h"

// Hash the trees structure such that two isomorphic trees have the same hash.
// T~(N*log(N)), S~(N)
inline string hashTree(const Tree* tree){
  if(!tree){return "";}

  vector<string> subhashes;
  subhashes.reserve(tree->children.size()+1);

  for(const auto child : tree->children){
    subhashes.push_back(hashTree(child));
  }

  std::sort(subhashes.begin(), subhashes.end());
  subhashes.push_back(")");
  const string hash = std::accumulate(subhashes.begin(), subhashes.end(), string("("));
  return hash;
}

#endif  // TREE_HASH_TREE_H_
