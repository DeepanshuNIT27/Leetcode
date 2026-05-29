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
// THIS IS A OPTIMAL SOLUTION OF COMPLEXITY O(N) 7 CONSTANT SPACE O(1).
// BUT HERE 2 CREATED 2 LIST THAT IS CONSTANT SPACE.
//SO IN METHOD 2 WE WILL DO IN PLACE MERGE .
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode* odd = new ListNode(0);
        ListNode* eve = new ListNode(0);
        bool flag = true;
        ListNode*temp1 = odd;
        ListNode*temp2 = eve;

        ListNode*curr = head;

        while(curr!=NULL){
           
           ListNode* forward = curr->next;
           if( flag ){
            temp1->next = curr;
            curr->next = NULL;
            temp1 = curr;
           }
           else{
            temp2->next = curr;
            curr->next = NULL;
            temp2= curr;
           }
           flag = !flag;
           curr = forward;
        }

        temp1->next = eve->next;
        return odd->next;
    }
};