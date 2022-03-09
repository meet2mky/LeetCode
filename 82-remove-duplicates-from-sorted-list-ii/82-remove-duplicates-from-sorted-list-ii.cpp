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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy;
        ListNode* ptr = &dummy;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            if(prev && curr->val == prev->val){
                // SKIP
            }else if(curr->next && curr->val == curr->next->val){
                // SKIP
            }
            else{
                ptr->next = curr;
                ptr = ptr->next;
            }
            prev = curr;
            curr = curr->next;
        }
        ptr->next = NULL;
        return dummy.next;
    }
};