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
    vector<TreeNode*> inorder;
public:
    void Inorder(TreeNode* root){
        if(!root)return;
        Inorder(root->left);
        inorder.push_back(root);
        Inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        Inorder(root);
        for(int i = 0; i < size(inorder); i++){
            inorder[i]->left = 0;
            inorder[i]->right = 0;
            if(i) inorder[i-1]->right = inorder[i];
        }
        return inorder[0];
    }
};