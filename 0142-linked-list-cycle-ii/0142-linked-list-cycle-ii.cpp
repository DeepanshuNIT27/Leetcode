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
// Brute force method O(N) space and time complexity
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,bool>mp;

       ListNode*curr = head;

        while(curr!=NULL){

            if(mp.find(curr)!=mp.end()) return curr;
            else{
                mp[curr] = true;
                curr = curr->next;
            }
        }
        return NULL;
    }
};