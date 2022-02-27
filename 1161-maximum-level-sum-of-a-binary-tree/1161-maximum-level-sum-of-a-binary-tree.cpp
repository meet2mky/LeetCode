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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> curr, next;
        int bestLevel = -1, ans = INT_MIN;
        int level = 1;
        curr.push(root);
        while(!curr.empty()){
            int lsum = 0;
            while(!curr.empty()){
                auto v = curr.front();
                lsum += v->val;
                curr.pop();
                if(v->left)next.push(v->left);
                if(v->right)next.push(v->right);
            }
            if(lsum > ans){
               ans = lsum;
               bestLevel = level;
            }
            swap(curr, next);
            level++;
        }
        return bestLevel;
    }
};