#ifndef EVERFLOW_ALGOS_BINARY_TREE_LOWEST_COMMON_ANCESTOR_H_
#define EVERFLOW_ALGOS_BINARY_TREE_LOWEST_COMMON_ANCESTOR_H_

// https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
//
// 235. 二叉搜索树的最近公共祖先
// 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

namespace {

class Solution {
 public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    TreeNode *ancestor = root;
    while (true) {
      if (p->val < ancestor->val && q->val < ancestor->val) {
        ancestor = ancestor->left;
      } else if (p->val > ancestor->val && q->val > ancestor->val) {
        ancestor = ancestor->right;
      } else {
        break;
      }
    }
    return ancestor;
  }
};

} // namespace

#endif //EVERFLOW_ALGOS_BINARY_TREE_LOWEST_COMMON_ANCESTOR_H_
