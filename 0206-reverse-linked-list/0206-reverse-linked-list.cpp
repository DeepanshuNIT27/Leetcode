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
//RECURSIVE SOLUTION
// ListNode*reverseList(ListNode* &prev,ListNode*&curr){
//     //BASE CASE
//     if(curr==NULL){
//         return prev;
//     }
//     ListNode* forward = curr->next;
//     curr->next = prev;
//     prev= curr;
//     curr= forward;
//     return reverseList(prev,curr);
// }
//     ListNode* reverseList(ListNode* head) {
//         ListNode*prev=NULL;
//         ListNode*curr=head;
//         ListNode*newHead = reverseList(prev,curr);
//         return newHead;
        
//     }
//ITERATIVE SOLUTION
ListNode*reverseList(ListNode*head){
    ListNode*prev=NULL;
    ListNode*curr=head;
    while(curr!=NULL){
        ListNode*forward = curr->next;
        curr->next= prev;
        prev = curr;
        curr= forward;
    }
    return prev;
}
};