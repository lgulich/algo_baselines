#ifndef DATA_STRUCTURES_QUEUE_H_
#define DATA_STRUCTURES_QUEUE_H_

#include <vector>

using namespace std;

class Queue {
 public:
  void pop() {
    if (!head_) { throw "List is empty"; }

    Node const* old_head = head_;
    head_ = head_->next;
    if (!head_) { tail_ = nullptr; }
    delete old_head;
    --size_;
  }

  void push(const int value) {
    Node* const new_tail = new Node(value);
    if (tail_) {
      tail_->next = new_tail;
      tail_ = new_tail;
    } else {
      tail_ = new_tail;
      head_ = new_tail;
    }
    ++size_;
  }

  int size() const { return size_; }

  int front() const {
    if (!head_) { throw "List is empty"; }
    return head_->value;
  }

  operator vector<int>() {
    vector<int> vec;
    vec.reserve(size_);
    Node* current = head_;
    while (current) {
      vec.push_back(current->value);
      current = current->next;
    }
    return vec;
  }

 private:
  struct Node {
    int value;
    Node* next = nullptr;
    Node(int value) : value(value) {}
  };

  int size_ = 0;
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

#endif  // DATA_STRUCTURES_QUEUE_H_
