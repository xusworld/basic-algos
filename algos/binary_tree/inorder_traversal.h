#ifndef EVERFLOW_ALGOS_BINARY_TREE_INORDER_TRAVERSAL_H_
#define EVERFLOW_ALGOS_BINARY_TREE_INORDER_TRAVERSAL_H_

// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
// 94. 二叉树的中序遍历
// 给定一个二叉树的根节点 root ，返回它的 中序 遍历。


namespace {

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// 个人实现的递归解法
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    if (root == nullptr) {
      return result;
    }
    auto left = inorderTraversal(root->left);
    result.insert(result.end(), left.begin(), left.end());
    result.push_back(root->val);
    auto right = inorderTraversal(root->right);
    result.insert(result.end(), right.begin(), right.end());
    return result;
  }
};

// 官方递归解法
class Solution {
 public:
  void inorder(TreeNode *root, vector<int> &res) {
    if (!root) {
      return;
    }
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
  }
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    inorder(root, res);
    return res;
  }
};

// 官方迭代解法
class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    stack <TreeNode *> stk;
    while (root != nullptr || !stk.empty()) {
      while (root != nullptr) {
        stk.push(root);
        root = root->left;
      }
      root = stk.top();
      stk.pop();
      res.push_back(root->val);
      root = root->right;
    }
    return res;
  }
};

} // namespace


#endif //EVERFLOW_ALGOS_BINARY_TREE_INORDER_TRAVERSAL_H_
