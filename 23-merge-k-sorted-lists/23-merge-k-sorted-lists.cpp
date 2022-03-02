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
  struct cmp{
    bool operator()(ListNode* a, ListNode* b){
      return a->val > b->val; 
    }
  };
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
    int k = lists.size();
    for(int i = 0; i < k; i++){
      if(lists[i]){
        pq.push(lists[i]);
        lists[i] = lists[i]->next;
      }
    }
    ListNode dummy;
    ListNode *ptr = &dummy;
    while(pq.size()){
      auto v = pq.top();
      pq.pop();
      if(v->next){
        pq.push(v->next);
      }
      ptr->next = v;
      ptr = ptr->next;
    }
    return dummy.next;
  }
};