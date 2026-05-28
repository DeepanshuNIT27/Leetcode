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
//METHOD-2 OPTIMAL METHOD COMPLEXTY O(1) FOR BOTH TIME AND SPACE
    void deleteNode(ListNode* node) {
        
        node->val = node->next->val;
        node->next = node->next->next;
        
    }
};