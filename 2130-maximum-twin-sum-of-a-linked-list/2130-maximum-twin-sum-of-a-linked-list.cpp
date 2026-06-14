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
// reverse the list 

ListNode* reverse(ListNode*head){

    ListNode*prev = NULL;
    while(head!=NULL){
        ListNode* forward = head->next;
          head->next = prev ;
          prev = head;
          head = forward;
    }
    return prev;
}

//finding the mid of the list 
ListNode* findMid(ListNode*slow , ListNode* fast){

    while(fast!=NULL && fast->next!=NULL){

        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

    int pairSum(ListNode* head) {
        
        ListNode* slow  = head;
        ListNode* fast  = head;

        ListNode* mid = findMid(slow,fast);
        
        ListNode* reverseHead = reverse(mid);

        int ans  = 0;
        ListNode*curr = head;
         while(reverseHead!=NULL){

            ans = max(ans, curr->val + reverseHead->val);
             curr = curr->next ;
             reverseHead = reverseHead->next;
         }
         return ans;
    }
};