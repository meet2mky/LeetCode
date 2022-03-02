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
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode* curr = head, *prev = nullptr;
      for(int i = 0; i < k; i++){
        if(!curr){
          return head;
        }
        prev = curr;
        curr = curr->next;
      }
      ListNode* rem = reverseKGroup(curr, k);
      prev->next = nullptr;
      curr = head;
      prev = nullptr;
      while(curr){
        auto tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
      }
      head->next = rem;
      return prev;
    }
};