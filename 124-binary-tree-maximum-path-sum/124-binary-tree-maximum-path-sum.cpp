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
class Solution {
public:
    int recurse(TreeNode* root, int& ans){
      if(!root) return -1000;
      int v = root->val;
      int l = -1000, r = -1000;
      if(root->left) l = recurse(root->left, ans);
      if(root->right) r = recurse(root->right, ans);
      ans = max(ans, max( v, max(v + l + r, max(v + l, v + r))));
      return max(v, v + max(l,r));
    }
    int maxPathSum(TreeNode* root) {
      int ans = -1000;
      recurse(root, ans);
      return ans;
    }
};