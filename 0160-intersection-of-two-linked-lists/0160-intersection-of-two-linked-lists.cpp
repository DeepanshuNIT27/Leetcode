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
// BRUTE FORCE APPROACH 
//COMPLEXITY O(N+M) TIME O(N) SPACE.
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_map<ListNode*,bool>mp;

        ListNode* curr = headA;
        while(curr!=NULL){
            mp[curr] = true;
            curr = curr->next;
        }

        curr = headB;
        while(curr!=NULL){
            if(mp.find(curr)!=mp.end()) return curr;
               curr = curr->next;
        }
        return NULL;
    }
};