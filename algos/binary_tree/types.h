#ifndef EVERFLOW_ALGOS_BINARY_TREE_TYPES_H_
#define EVERFLOW_ALGOS_BINARY_TREE_TYPES_H_

namespace algos {

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// t
} // namespace algos


#endif //EVERFLOW_ALGOS_BINARY_TREE_TYPES_H_