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
int getLength(ListNode*&head){
    int count =0;
   ListNode*temp =head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;

}
    ListNode* reverseKGroup(ListNode* head, int k) {
//LL IS EMPTY
if(head==NULL){
    return head;
}
//SINGLE NODE HO
if(head->next==NULL){
    return head;
}
//at least 2 node hogi;
int leg = getLength(head);
if(leg<k){
    return head;
}
ListNode*prev =NULL;
ListNode*curr = head;
int position =0;
while(position<k){
    ListNode*forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    position++;
}
//BAKI RECURSION SMBHAL LEGA
if(curr!=NULL){
    ListNode*recursionKaHead=reverseKGroup(curr,k);
    head->next =recursionKaHead;
}
return prev;
        
    }
};