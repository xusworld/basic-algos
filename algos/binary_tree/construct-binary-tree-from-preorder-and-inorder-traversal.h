#ifndef EVERFLOW_ALGOS_BINARY_TREE_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_H_
#define EVERFLOW_ALGOS_BINARY_TREE_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_H_

// https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
// 106. 从中序与后序遍历序列构造二叉树
// 根据一棵树的中序遍历与后序遍历构造二叉树。
namespace {

// 1. 递归解法
class Solution {
  int post_idx;
  int[] postorder;
  int[] inorder;
  Map<Integer, Integer> idx_map = new HashMap<Integer, Integer>();

 public TreeNode helper(int in_left, int in_right) {
    // 如果这里没有节点构造二叉树了，就结束
    if (in_left > in_right) {
      return null;
    }

    // 选择 post_idx 位置的元素作为当前子树根节点
    int root_val = postorder[post_idx];
    TreeNode root = new TreeNode(root_val);

    // 根据 root 所在位置分成左右两棵子树
    int index = idx_map.get(root_val);

    // 下标减一
    post_idx--;
    // 构造右子树
    root.right = helper(index + 1, in_right);
    // 构造左子树
    root.left = helper(in_left, index - 1);
    return root;
  }

 public TreeNode buildTree(int[] inorder, int[] postorder) {
    this.postorder = postorder;
    this.inorder = inorder;
    // 从后序遍历的最后一个元素开始
    post_idx = postorder.length - 1;

    // 建立（元素，下标）键值对的哈希表
    int idx = 0;
    for (Integer val : inorder) {
      idx_map.put(val, idx++);
    }

    return helper(0, inorder.length - 1);
  }
}

// 2. 迭代解法
class Solution {
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (postorder.size() == 0) {
      return nullptr;
    }
    auto root = new TreeNode(postorder[postorder.size() - 1]);
    auto s = stack<TreeNode*>();
    s.push(root);
    int inorderIndex = inorder.size() - 1;
    for (int i = int(postorder.size()) - 2; i >= 0; i--) {
      int postorderVal = postorder[i];
      auto node = s.top();
      if (node->val != inorder[inorderIndex]) {
        node->right = new TreeNode(postorderVal);
        s.push(node->right);
      } else {
        while (!s.empty() && s.top()->val == inorder[inorderIndex]) {
          node = s.top();
          s.pop();
          inorderIndex--;
        }
        node->left = new TreeNode(postorderVal);
        s.push(node->left);
      }
    }
    return root;
  }
};


} // namespace

#endif //EVERFLOW_ALGOS_BINARY_TREE_CONSTRUCT_BINARY_TREE_FROM_PREORDER_AND_INORDER_TRAVERSAL_H_
