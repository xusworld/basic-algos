#ifndef BASIC_ALGOS_ALGOS_BINARY_SEARCH_TREE_H_
#define BASIC_ALGOS_ALGOS_BINARY_SEARCH_TREE_H_

#include <iostream>
#include <vector>

#include "algos/log.h"

namespace algo {

template<typename DataType>
struct Node {
  DataType data;
  Node *left;
  Node *right;

  Node(const DataType &data) : data(data), left(nullptr), right(nullptr) {}
};

template<typename DataType>
class BinarySearchTree {
 public:
  BinarySearchTree() : root_(nullptr) {}
  ~BinarySearchTree() = default;

  void BuildBST(const std::vector<DataType> &);
  bool SearchNode(const DataType &);
  bool InsertNode(const DataType &);
  void DeleteNode(const DataType &);

  // TODO 将遍历方法从此类中剥离出来
  void PreOrderTraverse();
  void PostOrderTraverse();
  void InOrderTraverse();

 private:
  Node<DataType>* root_;
};

template<typename DataType>
void BinarySearchTree<DataType>::BuildBST(const std::vector<DataType> &inputs) {

  root_ = nullptr;

  if (inputs.size() == 0) {
    LOGF << "parameter inputs is invalid";
    return;
  }

  Node<DataType> *cur = nullptr;
  for (auto input : inputs) {
    if (root_ == nullptr) {
      Node<DataType> node(input);
      cur = &node;
      root_ = cur;
      continue;
    }

    // 从 root 节点开始遍历
    cur = root_;
    Node<DataType> *parent = nullptr;
    while (true) {

      // 左子树 : 若 当前遍历节点数值 <  cur.data
      if (cur != nullptr && input < cur->data) {
        parent = cur;
        cur = cur->left;
      }

      // 插入新的节点
      if (cur == nullptr) {
        auto node = Node<DataType>(input);
        cur = &node;
        parent->left = cur;
        break;
      }

      // 右子树 : 若 当前遍历节点数值 > cur.data
      if (cur != nullptr && input >= cur->data) {
        cur = cur->right;
      }

    }
  }

}

} // namespace algo

#endif //BASIC_ALGOS_ALGOS_BINARY_SEARCH_TREE_H_
