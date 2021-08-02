#ifndef EVERFLOW_ALGOS_BINARY_TREE_PATH_SUM_H_
#define EVERFLOW_ALGOS_BINARY_TREE_PATH_SUM_H_

// https://leetcode-cn.com/problems/path-sum/
// 112. 路径总和
//
// 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在 根节点到叶子节点的路径，
// 这条路径上所有节点值相加等于目标和 targetSum 。

namespace {

// 1. 广度优先遍历
class Solution {
 public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (root == nullptr) {
      return false;
    }
    queue < TreeNode * > que_node;
    queue<int> que_val;
    que_node.push(root);
    que_val.push(root->val);
    while (!que_node.empty()) {
      TreeNode *now = que_node.front();
      int temp = que_val.front();
      que_node.pop();
      que_val.pop();
      if (now->left == nullptr && now->right == nullptr) {
        if (temp == sum) {
          return true;
        }
        continue;
      }
      if (now->left != nullptr) {
        que_node.push(now->left);
        que_val.push(now->left->val + temp);
      }
      if (now->right != nullptr) {
        que_node.push(now->right);
        que_val.push(now->right->val + temp);
      }
    }
    return false;
  }
};

// 2. 递归
class Solution {
 public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (root == nullptr) {
      return false;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return sum == root->val;
    }
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
  }
};

} // namespace


#endif //EVERFLOW_ALGOS_BINARY_TREE_PATH_SUM_H_
