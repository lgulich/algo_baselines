#ifndef TESTING_TESTING_H_
#define TESTING_TESTING_H_

#include <gtest/gtest.h>

#include "graph/mutation.h"
#include "graph/types.h"
#include "list/types.h"
#include "tree/types.h"

template <typename Element>
void expect_eq(const vector<Element>& a, const vector<Element>& b) {
  EXPECT_EQ(a.size(), b.size());

  for (int i = 0; i < a.size(); ++i) { EXPECT_EQ(a[i], b[i]); }
}

inline void expect_eq(const AdjacencyList& a, const AdjacencyList& b) {
  EXPECT_EQ(a.size(), b.size());

  for (int node = 0; node < a.size(); ++node) {
    const auto& a_children = a[node];
    const auto& b_children = b[node];

    EXPECT_EQ(a_children.size(), b_children.size());
    for (const auto child : a_children) {
      EXPECT_NE(
          std::find(b_children.begin(), b_children.end(), child),
          b_children.end());
    }
  }
}

inline void expect_eq(const Tree* a, const Tree* b) {
  if (a == nullptr || b == nullptr) {
    EXPECT_EQ(a, b);
    return;
  }

  EXPECT_EQ(a->value, b->value);
  ASSERT_EQ(a->children.size(), b->children.size());

  for (int i = 0; i < a->children.size(); ++i) {
    expect_eq(a->children[i], b->children[i]);
  }
}

inline void expect_eq(const List* list, const vector<int>& vec) {
  auto vec_it = vec.begin();

  while (list) {
    EXPECT_EQ(list->value, *vec_it);
    list = list->next;
    ++vec_it;
  }

  EXPECT_EQ(vec_it, vec.end());
}

template <typename Element>
void expect_topological_order(
    const vector<Element>& order, const AdjacencyList& graph) {
  const AdjacencyList requirements = invertAdjacencyList(graph);
  vector<bool> closed(graph.size(), false);

  for (const int node : order) {
    for (const int requirement : requirements[node]) {
      EXPECT_TRUE(closed[requirement]);
    }
    closed[node] = true;
  }
}

#endif  // TESTING_TESTING_H_
