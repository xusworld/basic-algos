#ifndef EVERFLOW_ALGOS_BINARY_TREE_INVERT_BINARY_TREE_H_
#define EVERFLOW_ALGOS_BINARY_TREE_INVERT_BINARY_TREE_H_

// https://leetcode-cn.com/problems/invert-binary-tree/
// 226. 翻转二叉树

/*

输入：
     4
   /   \
  2     7
 / \   / \
1   3 6   9


输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1

 */
namespace {

// 递归解法
class Solution {
 public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }
    TreeNode *left = invertTree(root->left);
    TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
  }
};

//  非递归解法
class Solution {
 public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }

    stack < TreeNode * > st;
    st.push(root);

    while (!st.empty()) {
      TreeNode *node = st.top();
      st.pop();

      swap(node->left, node->right);

      if (node->right) {
        st.push(node->right);
      }

      if (node->left) {
        st.push(node->left);
      }
    }
    return root;
  }
};

}

#endif //EVERFLOW_ALGOS_BINARY_TREE_INVERT_BINARY_TREE_H_
