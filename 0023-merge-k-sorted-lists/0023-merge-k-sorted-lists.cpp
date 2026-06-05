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

struct cmp {
     bool operator()(ListNode*a ,ListNode*b) {
        return  a->val > b->val;
     }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
     // comparator khud likhna hoga 
        priority_queue<ListNode*, vector<ListNode*> , cmp >pq;
        for(auto&it:lists){
            if(it!=NULL){
               pq.push(it);
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        while(!pq.empty()){
           auto front = pq.top();
           pq.pop();
           dummy->next = front;
           dummy = front;
          if(front->next != NULL){
            pq.push(front->next);
          }
          front->next = NULL;
        }
        return curr->next;
    }
};