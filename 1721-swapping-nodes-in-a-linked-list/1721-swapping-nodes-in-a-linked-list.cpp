/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        k--;
        ListNode* tmp = head;
        ListNode* b = head, *a = head;
        while(k){
            tmp = tmp->next;
            k--;
        }
        a = tmp;
        while(tmp->next){
            tmp = tmp->next;
            b = b->next;
        }
        swap(a->val, b->val);
        return head;
    }
};