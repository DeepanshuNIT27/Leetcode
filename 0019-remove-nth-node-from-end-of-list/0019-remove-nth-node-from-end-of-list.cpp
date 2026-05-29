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

 // 2 pass solution first for count and second for delete 
 //complexity O(N) time ans O(1) space 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int count = 0;
        ListNode* curr = head;
        while(curr!=NULL){
            count++;
            curr = curr->next;
        }
        int index = count - n - 1;
        if(index == -1) {
            return head->next;
        }

        else{
             ListNode* temp = head;
            while(index>0){
               index -- ;
               temp = temp->next;
            }

            temp->next = temp->next->next;
        }
        return head;
    }
};