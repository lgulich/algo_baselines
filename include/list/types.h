#ifndef LINKED_LIST_TYPES_H_
#define LINKED_LIST_TYPES_H_

#include <iostream>
#include <vector>

struct List {
  int value;
  List* next = nullptr;

  List(const int value) : value(value) {}
};

inline List* createList(const std::vector<int>& data) {
  if (data.empty()) { return nullptr; }

  List* begin = new List(data.front());
  List* last = begin;
  for (int i = 1; i < data.size(); ++i) {
    last->next = new List(data[i]);
    last = last->next;
  }
  return begin;
}

inline void deleteList(List* list) {
  List* next;
  while (list) {
    next = list->next;
    delete list;
    list = next;
  }
}

inline std::ostream& print(List* list) {
  std::cout << '[';
  while (list) {
    std::cout << list->value << ',';
    list = list->next;
  }
  return std::cout << ']';
}

#endif  // LINKED_LIST_TYPES_H_
