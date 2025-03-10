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
 class compare{
    public :
    bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
    }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* ,vector<ListNode*> ,compare>pq;
        int totalrow = lists.size();
        ListNode* head = NULL;
        ListNode* tail = NULL;
        for(int row=0; row<totalrow ;row++){
            ListNode* temp = lists[row];
            if(temp!=NULL){
                pq.push(temp);
            }
        }
        while(!pq.empty()){
            ListNode* front = pq.top();
            pq.pop();
            if(head == NULL && tail == NULL){
                head = front;
                tail = front;
            }
            else{
                tail->next = front;
                tail = front;
            }
            if(tail->next!=NULL){
                pq.push(tail->next);
            }
        }
        return head;
    }
};