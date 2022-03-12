/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*> on;
        Node dummy(-1);
        Node* x = &dummy;
        Node* y = head;
        while(y){
            Node* ptr = new Node(y->val);
            x->next = ptr;
            on[y] = ptr;
            x = x->next;
            y = y->next;
        }
        y = head;
        x = dummy.next;
        while(y){
            if(y->random){
                x->random = on[y->random];
            }else{
                x->random = NULL;
            }
            y = y->next;
            x = x->next;
        }
        return dummy.next;
    }
};