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
// THIS IS A METHOD -1 WHERE THE TIME COMPLEXITY IS O(N) AND SPACE O(1)
    void deleteNode(ListNode* node) {
        
      ListNode * curr = node->next;
      ListNode* prev = node;

      prev->val = curr->val;
      while(curr->next){
        prev = curr;
        curr = curr->next;
        prev->val = curr->val;
      }
      prev->next = NULL;

    }
};