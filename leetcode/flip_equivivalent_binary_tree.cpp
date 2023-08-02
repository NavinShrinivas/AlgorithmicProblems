// Not all modes need to flipped, recursively check all possible flip or no flip
// conditions By using and and or conditions properly Problem :
// https://leetcode.com/problems/flip-equivalent-binary-trees/description/

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
  bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    if (root1 == NULL && root2 == NULL) {
      // If both are null then equal
      return true;
    }
    if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)) {
      return false;
    }
    if (root1->val == root2->val) {
      bool right_normal = flipEquiv(root1->right, root2->right);
      bool left_normal = flipEquiv(root1->left, root2->left);
      bool right_swap = flipEquiv(root1->right, root2->left);
      bool left_swap = flipEquiv(root1->left, root2->right);
      return ((right_normal && left_normal) || (right_swap && left_swap));
    } else {
      return false;
    }
  }
};
