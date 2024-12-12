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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode*temp1=list1;
        ListNode*curr1= temp1;
        ListNode*temp2=list2;
        ListNode*curr2= temp2;
        if(temp1==nullptr && temp2==nullptr){
            return nullptr;
        }
        else if(temp1==nullptr && temp2!=nullptr){
            return temp2;
        }
        else if(temp2==nullptr && temp1!=nullptr){
            return temp1;
        }
        
        ListNode*tail = new ListNode(-1);
        ListNode*ans =tail;
        while(temp1 && temp2){
            if(temp1->val<=temp2->val){
             ans->next = temp1;
             curr1 = temp1->next;
             temp1->next =nullptr;
             temp1=curr1;
             ans = ans->next;
            }
            else{
        ans->next =temp2;
        curr2 =temp2->next;
        temp2->next = nullptr;
        temp2=curr2;
        ans = ans->next;
            }
        }
        if(temp1){
            ans->next =temp1;
        }
        else if(temp2){
            ans->next =temp2;
        }
        
    ListNode*finalans = tail->next;
    delete tail;
    return finalans;
    }
};