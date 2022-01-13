#ifndef UTIL_STL_PRINT_H_
#define UTIL_STL_PRINT_H_

#include <iostream>
#include <vector>

template <typename It>
std::ostream& print(It begin, const It end) {
  std::cout << '[';
  while (begin != end) {
    std::cout << *begin << ',';
    ++begin;
  }
  return std::cout << ']';
}

template <typename Element>
std::ostream& print(const std::vector<Element>& vec) {
  return print(vec.begin(), vec.end());
}

template <typename Element>
std::ostream& printMat(const std::vector<std::vector<Element>>& vec) {
  for (const auto& row : vec) { print(row) << std::endl; }
  return std::cout;
}

#endif  // UTIL_STL_PRINT_H_
