#ifndef EVERFLOW_ALGOS_BINARY_TREE_MIRROR_TREE_H_
#define EVERFLOW_ALGOS_BINARY_TREE_MIRROR_TREE_H_

// https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
// 剑指 Offer 27. 二叉树的镜像
// 请完成一个函数，输入一个二叉树，该函数输出它的镜像。

/*
例如输入：
     4
   /   \
  2     7
 / \   / \
1   3 6   9

镜像输出：
     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/
namespace {

class Solution {
 public:
  TreeNode *mirrorTree(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }

    swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
    return root;
  }
};


class Solution {
 public:
  TreeNode* mirrorTree(TreeNode* root) {
    if (root == nullptr) {
      return nullptr;
    }
    TreeNode* left = mirrorTree(root->left);
    TreeNode* right = mirrorTree(root->right);
    root->left = right;
    root->right = left;
    return root;
  }
};


} // namespace

#endif //EVERFLOW_ALGOS_BINARY_TREE_MIRROR_TREE_H_
