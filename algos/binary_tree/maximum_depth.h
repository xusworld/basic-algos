#ifndef EVERFLOW_ALGOS_BINARY_TREE_MAXIMUM_DEPTH_H_
#define EVERFLOW_ALGOS_BINARY_TREE_MAXIMUM_DEPTH_H_

https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/

namespace {

// 个人递归解法
class Solution {
 public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
  }
};

// 官方递归解法
class Solution {
 public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

// 官方非递归解法
class Solution {
 public:
  int maxDepth(TreeNode *root) {
    if (root == nullptr) return 0;
    queue < TreeNode * > Q;
    Q.push(root);
    int ans = 0;
    while (!Q.empty()) {
      int sz = Q.size();
      while (sz > 0) {
        TreeNode *node = Q.front();
        Q.pop();
        if (node->left) Q.push(node->left);
        if (node->right) Q.push(node->right);
        sz -= 1;
      }
      ans += 1;
    }
    return ans;
  }
};

} // namespace

#endif //EVERFLOW_ALGOS_BINARY_TREE_MAXIMUM_DEPTH_H_
