# Algo Baselines [![Build and Test](https://github.com/lgulich/algo_baselines/actions/workflows/build_and_test.yml/badge.svg)](https://github.com/lgulich/algo_baselines/actions/workflows/build_and_test.yml)

Baseline implementations for common algorithms in C++.

The code in this repo will probably not be generic enough that you can use it
for your own problems, but feel free to use the implementations as a guide for
your own implementations.

## Data Structures

* Sparse Table<br>
  Data structure to allow fast range-queries (here for minimum values).<br>
  Creation: T\~O(N\*log(N)), S\~O(N\*log(N))<br>
  Query: T\~O(1), S\~O(1)

## Algorithms

### Dynamic Programming

* Knapsack<br>
  Find the items to fill a bag s.t. the value of the bag is maximized while
  constraining the maximum capacity C.<br>
  T\~O(N\*C), S\~O(N\*C)

* Mountain Scenes<br>
  Calculate the number of possible ways to draw a mountain scene.<br>
  T\~O(W\*S), S\~O(W\*S), with image width W and max rope length S.

* Narrow Art Gallery<br>
  Calculate the maximum sum of gallery rooms, while closing K rooms and keeping
  a way to walk through the gallery.
  T\~O(N\*K), S\~O(N\*K), with gallery length N

### Graphs

* Mutation - Invert Adjacency List<br>
  Invert an adjacency list such that every edge points in the other
  direction.<br>
  T\~O(E), S\~O(N+E)

* Traversal - Breadth First Search<br>
  Allows to traverse graph in a certain order.<br>
  T\~O(N+E), S\~O(N)

* Traversal - Depth First Search<br>
  Allows to traverse graph in a certain order.<br>
  T\~O(N+E), S\~O(N)

* Topological Sort - DFS Approach<br>
  Find a order of the nodes such that all ancestors of a node come before the
  node itself.<br>
  T\~O(N+E), S\~O(N)

* Topological Sort - Kahn's Algorithm<br>
  Find a order of the nodes such that all ancestors of a node come before the
  node itself.<br>
  T\~O(N+E), S\~O(N)

* Shortest Path - Bellfast Algorithm<br>
  T\~O(N\*E), S\~(N)<br>
  Find the shortest path to all nodes in graph from a start node. Additionally
  also finds nodes in negative cycles (shortest path = -inf).

* Shortest Path - Dijkstra Algorithm<br>
  T\~O(E\*log(N)), S\~(N)<br>
  Find the shortest path between two nodes.

### Lists

* Reverse List<br>
  T\~O(N), S\~(1)<br>
  Reverse the linked list.

### Search

* Pattern Matching - Knuth-Morris-Pratt Algorithm<br>
  T\~O(N+M), S\~(M)<br>
  Find if a pattern is contained in a vector. (N is size of vector, M is size of
  pattern).

* Binary Search<br>
  T\~O(log(N)), S\~(1)<br>
  Find position of an element in a sorted vector.

* Find Smaller Element<br>
  T\~O(log(N)), S\~(1)<br>
  Find element or next smaller element in a sorted vector.

### Sort

* Selection Sort <br>
  T\~O(N^2), S\~(1)<br>
  Sort by putting minimum element to front, continue with remaining vector.

* Merge Sort <br>
  T\~O(N\*log(N)), S\~(N)<br>
  Recursively split vector in half, sort both halves and then merge sorted
  halves.

### Trees

* Find Center<br>
  T\~O(N), S\~(N)<br>
  Finds the center of a graph with the tree property.

* Hash Tree<br>
  T\~O(N\*log(N)), S\~(N)<br>
  Computes the hash of a tree such that isomorphic trees have the same hash.

* Root Tree<br>
  T\~O(N), S\~(N)<br>
  Creates a rooted tree from a graph with the tree property.

* Determine Isomorphism<br>
  T\~O(N\*log(N)), S\~(N)<br>
  Determine if two unrooted trees are isomorphic (i.e. have same topology).

* Lowest Common Ancestor<br>
  T\~O(N), S\~(N)<br>
  Find the lowest common ancestor of two nodes.
