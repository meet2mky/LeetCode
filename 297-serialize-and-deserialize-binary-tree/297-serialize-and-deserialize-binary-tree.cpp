/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    void serialize(TreeNode* root, ostringstream& out){
        if(!root){
            out << "NULL "; 
            return;
        }
        out << root->val << " ";
        serialize(root->left, out);
        serialize(root->right, out);
    }
    TreeNode* deserialize(istringstream& in){
        string curr;
        in >> curr;
        if(curr == "NULL"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(curr));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    } 
public:
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));