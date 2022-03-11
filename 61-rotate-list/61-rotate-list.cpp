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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* tail = head, *mid = head;
        while(tail){ n++; tail = tail->next;}
        if(n == 0 || k%n == 0) return head;
        k %= n;
        tail = head;
        while(k--){
            tail = tail->next;
        }
        while(tail->next){
            tail = tail->next;
            mid = mid->next;
        }
        tail->next = head;
        head = mid->next;
        mid->next = NULL;
        return head;
    }
};