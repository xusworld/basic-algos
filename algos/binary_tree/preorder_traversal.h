#ifndef EVERFLOW_ALGOS_BINARY_TREE_PREORDER_TRAVERSAL_H_
#define EVERFLOW_ALGOS_BINARY_TREE_PREORDER_TRAVERSAL_H_

// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/


namespace {

// 个人递归
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    vector<int> result;
    result.push_back(root->val);
    auto left = preorderTraversal(root->left);
    result.insert(result.end(), left.begin(), left.end());
    auto right = preorderTraversal(root->right);
    result.insert(result.end(), right.begin(), right.end());
    return result;
  }
};

// 官方非递归
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if (root == nullptr) {
      return res;
    }

    stack<TreeNode*> stk;
    TreeNode* node = root;
    while (!stk.empty() || node != nullptr) {
      while (node != nullptr) {
        res.emplace_back(node->val);
        stk.emplace(node);
        node = node->left;
      }
      node = stk.top();
      stk.pop();
      node = node->right;
    }
    return res;
  }
};


} // namespace
#endif //EVERFLOW_ALGOS_BINARY_TREE_PREORDER_TRAVERSAL_H_
