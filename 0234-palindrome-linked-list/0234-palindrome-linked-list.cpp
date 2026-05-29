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

//ITERATIVE REVERSE METHOD
 ListNode* reverse(ListNode* pali){

   ListNode* prev = NULL;

   while(pali!=NULL){

    ListNode* forward = pali->next;
    pali->next = prev ;
    prev = pali ;
    pali = forward;
   }
   return prev;
   
 }
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next == NULL) return true;
        
        ListNode* slow = head;
        ListNode* fast  = head;

         while(fast!=NULL && fast->next!= NULL && fast->next->next!=NULL){

            slow = slow->next;
            fast = fast->next->next;
         }

         ListNode* pali = slow->next;
         slow->next = NULL;
         ListNode* rpali = reverse(pali);

         while(rpali!=NULL &&  head!=NULL){

            if(rpali->val != head->val) return false;

            rpali = rpali->next;
            head = head->next;
         }
         return true;
    }
};