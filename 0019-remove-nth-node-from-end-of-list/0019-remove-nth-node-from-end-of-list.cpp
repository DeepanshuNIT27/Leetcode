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
// Single pass solution time complexity O(N) and space O(N)
// But this is not optimal
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        unordered_map<int,ListNode*> mp;
        int total  = 0; 
        ListNode* curr = head;

        while(curr!=NULL){
            total++;
            mp[total] = curr;
            curr = curr->next;
        }
        int index = total - n;
        if(index==0) return head->next;

        ListNode* temp = mp[index];
        ListNode* del = mp[index+1];
        temp->next = del->next;
        delete del;
        return head;

    }
};