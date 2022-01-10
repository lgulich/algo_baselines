#include "tree/root_tree.h"

#include <gtest/gtest.h>

#include "testing/testing.h"

TEST(RootTree, EmptyGraph) {
  const AdjacencyList graph;
  Tree *tree = rootTree(graph, 0);
  Tree *expected = nullptr;
  expect_eq(tree, expected);

  deleteTree(tree);
  deleteTree(expected);
}

TEST(RootTree, LinearGraph) {
  const AdjacencyList directed_graph{
      {1},
      {2},
      {3},
      {},
  };
  const AdjacencyList undirected_graph = makeUndirected(directed_graph);
  Tree *tree = rootTree(undirected_graph, 0);

  Tree *expected = new Tree(0);
  expected->children.push_back(new Tree(1));
  expected->children[0]->children.push_back(new Tree(2));
  expected->children[0]->children[0]->children.push_back(new Tree(3));

  expect_eq(tree, expected);

  deleteTree(tree);
  deleteTree(expected);
}

TEST(RootTree, FullGraph) {
  const AdjacencyList directed_graph{
      {1, 4, 5}, // 0
      {2, 3},    // 1
      {},        // 2
      {},        // 3
      {},        // 4
      {6},       // 5
      {7, 8, 9}, // 6
      {},        // 7
      {},        // 8
      {},        // 9
  };
  const AdjacencyList undirected_graph = makeUndirected(directed_graph);
  Tree *tree = rootTree(undirected_graph, 0);

  Tree *expected = new Tree(0);
  expected->children = {new Tree(1), new Tree(4), new Tree(5)};
  expected->children[0]->children = {new Tree(2), new Tree(3)};
  expected->children[2]->children = {new Tree(6)};
  expected->children[2]->children[0]->children = {new Tree(7), new Tree(8),
                                                  new Tree(9)};

  expect_eq(tree, expected);

  deleteTree(tree);
  deleteTree(expected);
}
