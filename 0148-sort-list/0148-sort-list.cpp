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
 //OPTIMIZED APPROACH HERE WILL DO MERGE SORT 
 // COMPLEXITY O(N*LOG(N)) AND SPACE LOG(N) AUXALIARY CALL STACK. 
class Solution {
public:

// MERGE OPERATION 
ListNode* merge( ListNode* left, ListNode* right){

    ListNode dummy(-1);
    ListNode* tail = &dummy;

    while(left && right){

        if(left->val < right->val){

            tail->next = left;
            left = left->next;
        }

        else{
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }
    if(left) tail->next = left;
    else tail->next = right;

    return dummy.next;

    
}
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;

        // find middle 
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=NULL && fast->next!=NULL){

            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* right = slow->next;
        slow->next = NULL;

        ListNode* left = head;

        left = sortList(left);
        right = sortList(right);

        // merge them 
        return merge(left , right);
    }
};