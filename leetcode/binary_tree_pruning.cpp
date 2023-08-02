// Easy problem :)
// link : https://leetcode.com/problems/binary-tree-pruning/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  bool recursive_pruner(TreeNode *root) {
    if (root == NULL) {
      return false;
    }
    if (root->val == 1) {
      // Need to check if either subtrees are full of 0
      bool check_right = recursive_pruner(root->right);
      bool check_left = recursive_pruner(root->left);
      if (check_right == false) {
        root->right = NULL;
      }
      if (check_left == false) {
        root->left = NULL;
      }
      return true; // As anyways the node value is 1 and we have pruned all 0
                   // subtrees
    } else {
      // We need to check if any subtree has 1
      bool check_right = recursive_pruner(root->right);
      bool check_left = recursive_pruner(root->left);
      // prune if any of the subtrees are all 0 :
      if (check_right == false) {
        root->right = NULL;
      }
      if (check_left == false) {
        root->left = NULL;
      }
      // If any one subtree is not all 0, we need to preserve this subtree
      if (check_right) {
        return true;
      }
      if (check_left) {
        return true;
      }
      return false;
    }
  }
  TreeNode *pruneTree(TreeNode *root) {
    bool ans = recursive_pruner(root);
    if (ans) {
      return root;
    } else {
      return NULL;
    }
  }
};
