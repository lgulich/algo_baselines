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

add_executable(all_tests
  test/graph/main.cc
  test/graph/traversal_test.cc
  test/graph/mutation_test.cc
  test/graph/topological_sort_test.cc
  )
target_link_libraries(all_tests
  gtest
  )

gtest_discover_tests(all_tests)
