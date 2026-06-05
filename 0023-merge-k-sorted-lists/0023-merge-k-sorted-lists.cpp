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

// LEARNING KI COMPARE WALA CHIJ HOTA HAI USKO LIST WAGERA KE CASE ME KHUD SE LIKHNA HOTA HAI NI TO HEAP MEMORY ADDRESS KE BASE PE SORT KRNE LG JAYEGA SO BETTER TO WRITE YOUR COMP ONLY.

// IF NUMBER OF ALL NODES ARE N
// TOTAL NO OF LIST = K
// COMPLEXITY O(NLOGK) AND SPACE O(LOGK)
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
        }
        return curr->next;
    }
};