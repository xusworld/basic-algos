#ifndef EVERFLOW_ALGOS_BINARY_TREE_CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_TRAVERSAL_H_
#define EVERFLOW_ALGOS_BINARY_TREE_CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_TRAVERSAL_H_

// https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// 105. 从前序与中序遍历序列构造二叉树
// 给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。

namespace {

// 1. 递归解法
class Solution {
 private:
  unordered_map<int, int> index;

 public:
  TreeNode* myBuildTree(const vector<int>& preorder, const vector<int>& inorder, int preorder_left, int preorder_right, int inorder_left, int inorder_right) {
    if (preorder_left > preorder_right) {
      return nullptr;
    }

    // 前序遍历中的第一个节点就是根节点
    int preorder_root = preorder_left;
    // 在中序遍历中定位根节点
    int inorder_root = index[preorder[preorder_root]];

    // 先把根节点建立出来
    TreeNode* root = new TreeNode(preorder[preorder_root]);
    // 得到左子树中的节点数目
    int size_left_subtree = inorder_root - inorder_left;
    // 递归地构造左子树，并连接到根节点
    // 先序遍历中「从 左边界+1 开始的 size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到 根节点定位-1」的元素
    root->left = myBuildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree, inorder_left, inorder_root - 1);
    // 递归地构造右子树，并连接到根节点
    // 先序遍历中「从 左边界+1+左子树节点数目 开始到 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
    root->right = myBuildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right, inorder_root + 1, inorder_right);
    return root;
  }

  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    // 构造哈希映射，帮助我们快速定位根节点
    for (int i = 0; i < n; ++i) {
      index[inorder[i]] = i;
    }
    return myBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
  }
};

// 2. 迭代解法
class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (!preorder.size()) {
      return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[0]);
    stack<TreeNode*> stk;
    stk.push(root);
    int inorderIndex = 0;
    for (int i = 1; i < preorder.size(); ++i) {
      int preorderVal = preorder[i];
      TreeNode* node = stk.top();
      if (node->val != inorder[inorderIndex]) {
        node->left = new TreeNode(preorderVal);
        stk.push(node->left);
      }
      else {
        while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
          node = stk.top();
          stk.pop();
          ++inorderIndex;
        }
        node->right = new TreeNode(preorderVal);
        stk.push(node->right);
      }
    }
    return root;
  }
};


} // namespace


#endif //EVERFLOW_ALGOS_BINARY_TREE_CONSTRUCT_BINARY_TREE_FROM_INORDER_AND_POSTORDER_TRAVERSAL_H_
