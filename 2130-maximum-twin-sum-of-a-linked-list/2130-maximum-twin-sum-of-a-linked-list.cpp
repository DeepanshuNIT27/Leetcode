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
    int pairSum(ListNode* head) {
        
        unordered_map<int,int>mp;
        ListNode*temp = head;
        int n = 0;

        while(temp){
            mp[n] = temp->val;
            temp = temp->next;
            n++;    
        }
        int  t = (n/2)-1;
        int ans = 0;
        int i = 0;
        while(i<=t){
           
           ans = max(ans, head->val + mp[n-1-i]);
           head = head->next;
            i++;
        }
        return ans;
    }
};