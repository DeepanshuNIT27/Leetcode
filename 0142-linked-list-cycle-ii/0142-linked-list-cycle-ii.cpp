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
// SLOW FAST POINTER APPROACH AGR DONO KISI SAME POINT PE MILE MEANS CYCLE PRESENT HAI AB VO DTAR NIKALNE KE LIYE SLOW KO HEAD PE LE JA AB DONO KO 1-1 STEP SE BADATE CHAL AGAIN JAHA MILE VHI START POINT TH CYCLE KA
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next == NULL) return NULL;
        
        ListNode* slow =  head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){

            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
        }
        }
        return NULL;
    }
};