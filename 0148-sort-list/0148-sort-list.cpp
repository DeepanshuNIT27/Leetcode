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
//BRUTE FORCE SOLUTION COMPLEXITY O(N) FOR TIME &SPACE BOTH.
    ListNode* sortList(ListNode* head) {
        vector<int>v;
        ListNode* curr = head;

        while(curr!=NULL){
            v.push_back(curr->val);
            curr = curr->next;
        }

        sort(v.begin(),v.end());
        int i = 0;

        curr = head;
        while(curr!= NULL){
            curr->val =v[i];
            i++;
            curr = curr->next;
        }
        return head;
    }
};