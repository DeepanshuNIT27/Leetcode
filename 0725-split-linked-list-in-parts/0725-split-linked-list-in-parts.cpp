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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int N = 0;
        ListNode*temp = head;
        while(temp!=nullptr){
            N++;
            temp = temp->next;
        }
        //SIZE OF EACH BUCKET
        int partSize = N/k;
        int extraNodes = N%k;
        vector<ListNode*>ans(k,nullptr);
        ListNode* it = head;
        for(int i=0; i<k && it;i++){
            ans[i] = it;
            int currentPartSize = partSize+ (extraNodes-- >0 ? 1 : 0 );
            for(int j=0 ;j <currentPartSize - 1 ;j++)
                it = it->next;
    ListNode* NextPartstarting = it->next;
    it->next = nullptr;
    it = NextPartstarting;


        }
        
        return ans;
    }
};