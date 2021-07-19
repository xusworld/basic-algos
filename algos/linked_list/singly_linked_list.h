#ifndef EVERFLOW_ALGOS_LINKED_LIST_SINGLY_LINKED_LIST_H_
#define EVERFLOW_ALGOS_LINKED_LIST_SINGLY_LINKED_LIST_H_

namespace algos {

struct Node {
  int data;
  Node *head;
  Node *tail;
};

class SinglyLinkedList {
 public:
  void push_back(int data);

  void push_front(int data);

  void insert_after(Node *prev, int data);

 private:
  Node *head;
  int size;
};

void SinglyLinkedList::push_back(int data) {

}

void SinglyLinkedList::push_front(int data) {

}

void SinglyLinkedList::insert_after(Node *prev, int data) {

}

} // namespace algos

#endif //EVERFLOW_ALGOS_LINKED_LIST_SINGLY_LINKED_LIST_H_
