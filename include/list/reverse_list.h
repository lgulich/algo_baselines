#ifndef LIST_REVERSE_LIST_H_
#define LIST_REVERSE_LIST_H_

#include "list/types.h"

// T~O(N), S~O(1)
List* reverseList(List* list) {
  if (!list) { return nullptr; }

  List* prev = nullptr;
  List* curr = list;
  List* next = curr->next;

  while (true) {
    curr->next = prev;
    if (!next) { break; }
    prev = curr;
    curr = next;
    next = curr->next;
  }

  return curr;
}

#endif  // LIST_REVERSE_LIST_H_
