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
    int passed;
    int ans;
public:
    void inorder(TreeNode* root, int k){
        if(!root || ans > -1)return;
        inorder(root->left,k);
        if(k == passed + 1){
            ans = root->val;
        }
        passed++;
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        passed = 0;
        ans = -1;
        inorder(root,k);
        return ans;
    }
};