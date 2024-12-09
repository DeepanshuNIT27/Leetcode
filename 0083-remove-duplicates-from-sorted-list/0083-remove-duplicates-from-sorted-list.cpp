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
    ListNode* deleteDuplicates(ListNode* head) {
        //LL IS EMPTY
        if(head==NULL){
            return head;
        }
        //SINGLE ELEMENT PRESENT HAI
        if(head->next==NULL){
            return head;
        }
        //AT LEAST 2 NODE HAI
        ListNode* prev=head;
        ListNode*temp=head->next;
        while(temp!=NULL){
            if(prev->val==temp->val){
                prev->next =temp->next;
                temp->next =NULL;
                delete temp;
            }
            else{
                prev = prev->next;
            }
            temp = prev->next;
        }
        return head;
    }
};