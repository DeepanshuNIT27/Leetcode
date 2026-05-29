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
//OPTIMAL SOLUTION O(N) TIME ANS O(1) AND SINGLE PASS.
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode * temp = new ListNode(0);
        temp->next = head;
        ListNode* slow= temp;
        ListNode* fast = temp;

        for(int i=0;i<n;i++){
            fast = fast->next;
        }

        while( fast!=NULL && fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* del = slow->next;
        slow->next = del->next;
        delete del;
        return temp->next;
    }
};