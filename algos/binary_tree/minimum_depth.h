#ifndef EVERFLOW_ALGOS_BINARY_TREE_MINIMUM_DEPTH_H_
#define EVERFLOW_ALGOS_BINARY_TREE_MINIMUM_DEPTH_H_

// https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/
// 111. 二叉树的最小深度
// 给定一个二叉树，找出其最小深度。
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

namespace {

class Solution {
 public:
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    if (root->left == nullptr && root->right == nullptr) {
      return 1;
    }

    int min_depth = INT_MAX;
    if (root->left != nullptr) {
      min_depth = min(minDepth(root->left), min_depth);
    }
    if (root->right != nullptr) {
      min_depth = min(minDepth(root->right), min_depth);
    }

    return min_depth + 1;
  }
};

} // namespace

#endif //EVERFLOW_ALGOS_BINARY_TREE_MINIMUM_DEPTH_H_
