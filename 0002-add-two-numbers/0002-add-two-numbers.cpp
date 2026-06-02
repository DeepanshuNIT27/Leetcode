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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* final= new ListNode(-1);
        ListNode* ans = final;

        ListNode*templ1 = l1;
        ListNode* templ2 = l2;
        int carray = 0;

        while(templ1!=NULL && templ2!=NULL){

            int d = templ1->val + templ2->val + carray;
            ListNode* curr = new ListNode(d%10);
            carray = d/10;
            ans->next = curr;
            ans = curr;

            templ1 = templ1->next;
            templ2 = templ2->next;
        }
        if(templ1){
            while(templ1!=NULL){
                int d = carray + templ1->val;
                 ListNode* curr = new ListNode(d%10);
                 carray = d/10;
                 ans->next = curr;
                 ans = curr;
                 templ1 = templ1->next;
            }
        }
        if(templ2){
             while(templ2!=NULL){
                int d = carray + templ2->val;
                 ListNode* curr = new ListNode(d%10);
                 carray = d/10;
                 ans->next = curr;
                 ans = curr;
                 templ2 = templ2->next;
            }
        }
        if(carray){
             ListNode* curr = new ListNode(carray);
             carray = 0;
             ans->next = curr;
             ans = curr;
        }
        return final->next;
    }
};