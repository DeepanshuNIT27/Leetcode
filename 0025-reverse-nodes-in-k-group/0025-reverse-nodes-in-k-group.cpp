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
ListNode* reverse(ListNode*start , int k){

   ListNode* prev = NULL;
    ListNode* curr  = start;
while(k){
    k--;
    ListNode* front = curr->next;
    curr->next = prev ;
    prev = curr;
    curr = front; 
   }
return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* prev  = NULL;
        ListNode* start = NULL;

        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* temp = curr;
            int count = 0;

            while(temp!=NULL && count<k){
                count++;
                temp = temp->next;
            }
            if(count==k){
             ListNode* ans = reverse(curr,k);
             if(start == NULL) start = ans;
             if(prev == NULL) {
                prev = curr;
             }
             else{
                prev->next = ans;
                prev = curr;
             }
            }

            else{
                prev->next = curr;
                break;
            }

            curr = temp;
        }
        return start;
    }
};