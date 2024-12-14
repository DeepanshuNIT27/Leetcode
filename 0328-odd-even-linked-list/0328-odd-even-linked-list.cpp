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
    ListNode* oddEvenList(ListNode* head) {
        ListNode*temp =head;
        int i =1;
        ListNode* odd = new ListNode(-1);
        ListNode*odd1=odd;
         ListNode*eve = new ListNode(-1);
        ListNode*eve1=eve;
        while(temp!=nullptr){
            if(i%2==0){
                //EVEN ME DALO
                eve1->next = temp;
                temp =temp->next;
                eve1 = eve1->next;
                i++;
            }
            else{
                //ODD ME DALO
                odd1->next = temp;
                temp =temp->next;
                odd1 = odd1->next;
                i++;
            }
        }
        //DONO KO MERGE KR DO.
        eve1->next = nullptr;
        odd1->next = eve->next;
    ListNode*Result = odd->next;
    delete odd;
    delete eve;
    return Result;

        
    }
};