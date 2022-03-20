/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public void preOrder(Node root, List<Integer> myList){
        if(root == null) return;
        myList.add(root.val);
        for(Node child: root.children){
            preOrder(child, myList);
        } 
    }
    public List<Integer> preorder(Node root) {
        List<Integer> myList = new ArrayList<Integer>();
        preOrder(root, myList);
        return myList;
    }
}