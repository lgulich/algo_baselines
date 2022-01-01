# Algo Baselines [![CI](https://github.com/lgulich/algo_baselines/actions/workflows/ci.yml/badge.svg?branch=master)](https://github.com/lgulich/algo_baselines/actions/workflows/ci.yml)

Baseline implementations for common algorithms in C++.

The code in this repo will probably not be generic enough that you can use it
for your own problems, but feel free to use the implementations as a guide for
your own implementations.

## Algorithms

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
