#ifndef EVERFLOW_ALGOS_BINARY_TREE_POSTORDER_TRAVERSAL_H_
#define EVERFLOW_ALGOS_BINARY_TREE_POSTORDER_TRAVERSAL_H_

// https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
// 145. 二叉树的后序遍历
// 给定一个二叉树，返回它的 后序 遍历

namespace {

class Solution {
 public:
  void postorder(TreeNode *root, vector<int> &res) {
    if (root == nullptr) {
      return;
    }
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
  }

  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    postorder(root, res);
    return res;
  }
};

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    if (root == nullptr) {
      return res;
    }

    stack<TreeNode *> stk;
    TreeNode *prev = nullptr;
    while (root != nullptr || !stk.empty()) {
      while (root != nullptr) {
        stk.emplace(root);
        root = root->left;
      }
      root = stk.top();
      stk.pop();
      if (root->right == nullptr || root->right == prev) {
        res.emplace_back(root->val);
        prev = root;
        root = nullptr;
      } else {
        stk.emplace(root);
        root = root->right;
      }
    }
    return res;
  }
};


}
#endif //EVERFLOW_ALGOS_BINARY_TREE_POSTORDER_TRAVERSAL_H_
