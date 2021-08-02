#ifndef EVERFLOW_ALGOS_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H_
#define EVERFLOW_ALGOS_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H_


// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
// 102. 二叉树的层序遍历
//
// 给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。



namespace {
class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector <vector <int>> ret;
    if (root == nullptr) {
      return ret;
    }

    queue <TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      int currentLevelSize = q.size();
      ret.push_back(vector <int> ());
      for (int i = 1; i <= currentLevelSize; ++i) {
        auto node = q.front();
        q.pop();
        ret.back().push_back(node->val);
        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }
    }

    return ret;
  }
};

}

#endif //EVERFLOW_ALGOS_BINARY_TREE_LEVEL_ORDER_TRAVERSAL_H_
