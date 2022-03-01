/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void copyTree(Node* original, Node* copy){
        int countOfChildren = original->children.size();
        for(int i = 0; i < countOfChildren; i++){
            Node* currentChild = original->children[i];
            Node* copiedChild = new Node(currentChild->val);
            copy->children.push_back(copiedChild);
            copyTree(currentChild, copiedChild);
        }
    }
    Node* cloneTree(Node* root) {
        if(root == NULL) return NULL;
        Node* copyRoot = new Node(root->val);
        Node* copiedTree = copyRoot;
        copyTree(root, copyRoot);
        return copiedTree;
    }
};