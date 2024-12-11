/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
ListNode*hascycle(ListNode*head){
    ListNode*slow=head;
    ListNode*fast = head;
    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow = slow->next;
            if(fast==slow){
                return fast;
            }
        }
    }
    return NULL;
}
    ListNode *detectCycle(ListNode *head) {
        
        ListNode*fast =hascycle(head);
        //NO CYCLE IS PRESENT
        if(fast==NULL){
            return NULL;
        }
        ListNode*slow = head;
        //CYCLE S PRESENT
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;

        }
        return slow;
        
    }
};