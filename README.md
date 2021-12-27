# Algo Baselines [![CI](https://github.com/lgulich/algo_baselines/actions/workflows/ci.yml/badge.svg?branch=master)](https://github.com/lgulich/algo_baselines/actions/workflows/ci.yml)

Baseline implementations for common algorithms in C++.

The code in this repo will probably not be generic enough that you can use it
for your own problems, but feel free to use the implementations as a guide for
your own implementations.

## Algorithms

### Graphs

* Mutation - Invert Adjacency List
Invert an adjacency list such that every edge points in the other direction.
T~O(E), S~O(N+E)

* Traversal - Breadth First Search
Allows to traverse graph in a certain order.
T~O(N+E), S~O(N)

* Traversal - Depth First Search
Allows to traverse graph in a certain order.
T~O(N+E), S~O(N)

* Topological Sort - DFS Approach
Find a order of the nodes such that all ancestors of a node come before the node
itself.
T~O(N+E), S~O(N)

* Topological Sort - Kahn's Algorithm
Find a order of the nodes such that all ancestors of a node come before the node
itself.
T~O(N+E), S~O(N)
