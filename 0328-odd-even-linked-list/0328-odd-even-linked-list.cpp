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
// THIS IS ALSO OPTIMIZED CODE COMPLEXITY O(N) TIME AND O(1) SPACE 
// IN PREVIOUS SOUTION WE SAW THAT WE CREATED THE NEW LIST BUT HERE WE DID 
// WITH OUT CREATING ANY NODE THAT IS INPLACE MERGING 
    ListNode* oddEvenList(ListNode* head) {

        if(head == NULL || head->next == NULL) return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenhead = even;

        while(even !=NULL && even->next!=NULL){

            odd->next = even->next;
            odd = even->next;

            even->next = odd->next;
            even = odd->next;
        }

        odd->next = evenhead;
        return head;

    }
};