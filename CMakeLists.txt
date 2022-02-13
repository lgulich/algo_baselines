cmake_minimum_required(VERSION 3.14)
project(algo_baselines)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
  )
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

include_directories(include)

enable_testing()

## Datastructures
add_executable(data_structures_tests
  test/data_structures/main.cc
  test/data_structures/binary_search_tree_test.cc
  test/data_structures/sparse_table_test.cc
  test/data_structures/queue_test.cc
  test/data_structures/quick_union_test.cc
  )
target_link_libraries(data_structures_tests gtest)
gtest_discover_tests(data_structures_tests)


## Dynamic Programming
add_executable(dynamic_programming_tests
  test/dynamic_programming/mountain_scenes_test.cc
  test/dynamic_programming/narrow_art_gallery_test.cc
  test/dynamic_programming/knapsack_test.cc
  test/dynamic_programming/main.cc
  )
target_link_libraries(dynamic_programming_tests gtest)
gtest_discover_tests(dynamic_programming_tests)


## Graphs
add_executable(graph_tests
  test/graph/main.cc
  test/graph/mutation_test.cc
  test/graph/shortest_path_test.cc
  test/graph/topological_sort_test.cc
  test/graph/traversal_test.cc
  )
target_link_libraries(graph_tests gtest)
gtest_discover_tests(graph_tests)


## Lists
add_executable(list_tests
  test/list/main.cc
  test/list/reverse_list_test.cc
  )
target_link_libraries(list_tests gtest)
gtest_discover_tests(list_tests)


## Search
add_executable(search_tests
  test/search/main.cc
  test/search/binary_search_test.cc
  test/search/quick_select_test.cc
  test/search/search_pattern_kmp_test.cc
  test/search/search_smaller_value_test.cc
  )
target_link_libraries(search_tests gtest)
gtest_discover_tests(search_tests)


## Sort
add_executable(sort_tests
  test/sort/main.cc
  test/sort/merge_sort_test.cc
  test/sort/general_sort_test.cc
  )
target_link_libraries(sort_tests gtest)
gtest_discover_tests(sort_tests)


## Trees
add_executable(tree_tests
  test/tree/main.cc
  test/tree/find_center_test.cc
  test/tree/hash_tree_test.cc
  test/tree/is_isomorphic_test.cc
  test/tree/lowest_common_ancestor_test.cc
  test/tree/root_tree_test.cc
  )
target_link_libraries(tree_tests gtest)
gtest_discover_tests(tree_tests)
