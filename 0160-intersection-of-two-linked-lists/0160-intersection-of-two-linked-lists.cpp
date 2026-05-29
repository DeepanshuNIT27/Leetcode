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
// OPTIMIZED APPROACH  COMPLEXTY O(N+M) AND SPACE CONSTANT O(1).
// AGAR VO INTERSECT KREGI MEANS SAME TAILSHARE KREGI DONO KA LENGTH NIKAL /LO AB JITNA LENGTH KA DIFF HAI UTNA JYADA LENGTH WALE KO AAGE BADHAO
//AB SATH ME COMPARE KRTE CHALO JO SAME NODE AAYA VO ANS HOGA
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int count1 = 0;
        int count2 = 0;

        ListNode* curr = headA;
        while(curr!=NULL){
            count1++;
            curr = curr->next;
        }
        curr = headB;
        while(curr!=NULL){
            count2++;
            curr = curr->next;
        }
        int d = abs(count1-count2);
        ListNode* startA = headA;
        ListNode* startB = headB;
        if(max(count1,count2)== count1){
            for(int i=0;i<d;i++){
              startA = startA->next;
            }
        }
        else {
             for(int i=0;i<d;i++){
              startB = startB->next;
            }
        }
        while(startA!=NULL && startB!=NULL){

            if(startA == startB) return startA;
            startA = startA->next;
            startB = startB->next;
        }
        return NULL;
    }
};