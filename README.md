# Algo Baselines [![Build and Test](https://github.com/lgulich/algo_baselines/actions/workflows/build_and_test.yml/badge.svg)](https://github.com/lgulich/algo_baselines/actions/workflows/build_and_test.yml)

Baseline implementations for common algorithms in C++.

The code in this repo will probably not be generic enough that you can use it
for your own problems, but feel free to use the implementations as a guide for
your own implementations.

## Data Structures

* [Sparse Table](include/data_structures/sparse_table.h)<br>
  Data structure to allow fast range-queries (here for minimum values).<br>
  Creation: T\~O(N\*log(N)), S\~O(N\*log(N))<br>
  Query: T\~O(1), S\~O(1)
* [Quick Union](include/data_structures/quick_union.h)<br>
  Data structure that allows to connect nodes and efficiently query if two nodes
  are connected.
  Creation: T\~O(N), S\~O(N)<br>
  Connect: T\~O(log(N)), S\~O(1)
  Query: T\~O(log(N)), S\~O(1)

## Algorithms

### Dynamic Programming

* [Knapsack](include/dynamic_programming/knapsack.h)<br>
  Find the items to fill a bag s.t. the value of the bag is maximized while
  constraining the maximum capacity C.<br>
  T\~O(N\*C), S\~O(N\*C)

* [Mountain Scenes](include/dynamic_programming/mountain_scenes.h)<br>
  Calculate the number of possible ways to draw a mountain scene.<br>
  T\~O(W\*S), S\~O(W\*S), with image width W and max rope length S.

* [Narrow Art Gallery](include/dynamic_programming/narrow_art_gallery.h)<br>
  Calculate the maximum sum of gallery rooms, while closing K rooms and keeping
  a way to walk through the gallery.
  T\~O(N\*K), S\~O(N\*K), with gallery length N

### Graphs

* [Mutation - Invert Adjacency List](include/graph/mutation.h)<br>
  Invert an adjacency list such that every edge points in the other
  direction.<br>
  T\~O(E), S\~O(N+E)

* [Traversal - Breadth First Search](include/graph/traversal.h)<br>
  Allows to traverse graph in a certain order.<br>
  T\~O(N+E), S\~O(N)

* [Traversal - Depth First Search](include/graph/traversal.h)<br>
  Allows to traverse graph in a certain order.<br>
  T\~O(N+E), S\~O(N)

* [Topological Sort - DFS Approach](include/graph/topological_sort.h)<br>
  Find a order of the nodes such that all ancestors of a node come before the
  node itself.<br>
  T\~O(N+E), S\~O(N)

* [Topological Sort - Kahn's Algorithm](include/graph/topological_sort.h)<br>
  Find a order of the nodes such that all ancestors of a node come before the
  node itself.<br>
  T\~O(N+E), S\~O(N)

* [Shortest Path - Bellfast Algorithm](include/graph/shortest_path.h)<br>
  T\~O(N\*E), S\~(N)<br>
  Find the shortest path to all nodes in graph from a start node. Additionally
  also finds nodes in negative cycles (shortest path = -inf).

* [Shortest Path - Dijkstra Algorithm](include/graph/shortest_path.h)<br>
  T\~O(E\*log(N)), S\~(N)<br>
  Find the shortest path between two nodes.

### Lists

* [Reverse List](include/list/reverse_list.h)<br>
  T\~O(N), S\~(1)<br>
  Reverse the linked list.

### Search

* [Binary Search](include/search/binary_search.h)<br>
  T\~O(log(N)), S\~(1)<br>
  Find position of an element in a sorted vector.

* [Pattern Matching - Knuth-Morris-Pratt Algorithm](include/search/search_pattern_kmp.h)<br>
  T\~O(N+M), S\~(M)<br>
  Find if a pattern is contained in a vector. (N is size of vector, M is size of
  pattern).

* [Search Smaller Element](include/search/search_smaller_element.h)<br>
  T\~O(log(N)), S\~(1)<br>
  Find element or next smaller element in a sorted vector.

* [Quick Select](include/search/quick_select.h)<br>
  T\~O(N\*log(N)), S\~(1)<br>
  Find k-smallest element in vector and partition around it.

### Sort

* [Merge Sort](include/sort/merge_sort.h)<br>
  T\~O(N\*log(N)), S\~(N)<br>
  Recursively split vector in half, sort both halves and then merge sorted
  halves.

* [Quick Sort](include/sort/quick_sort.h)<br>
  T\~O(N\*log(N)), S\~(log(N))<br>
  Recursively partition array into elements smaller and bigger than pivot.

* [Selection Sort](include/sort/selection_sort.h)<br>
  T\~O(N^2), S\~(1)<br>
  Sort by putting minimum element to front, continue with remaining vector.

### Trees

* [Find Center](include/tree/find_center.h)<br>
  T\~O(N), S\~(N)<br>
  Finds the center of a graph with the tree property.

* [Hash Tree](include/tree/hash_tree.h)<br>
  T\~O(N\*log(N)), S\~(N)<br>
  Computes the hash of a tree such that isomorphic trees have the same hash.

* [Root Tree](include/tree/root_tree.h)<br>
  T\~O(N), S\~(N)<br>
  Creates a rooted tree from a graph with the tree property.

* [Determine Isomorphism](include/tree/is_isomorphic.h)<br>
  T\~O(N\*log(N)), S\~(N)<br>
  Determine if two unrooted trees are isomorphic (i.e. have same topology).

* [Lowest Common Ancestor](include/tree/lowest_common_ancestor.h)<br>
  T\~O(N), S\~(N)<br>
  Find the lowest common ancestor of two nodes.
