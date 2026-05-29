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
//BRUTE FORCE - FIRST TRAVERSE THE LINKEDLIST AND STORE  ALL VALUE ON A STRING THEN CHECK WHETHER THE STRING IS PALINDROM OR NOT 
    bool isPalindrome(ListNode* head) {
        
        string s = "";
        ListNode* curr = head;

        while(curr!=NULL){

             s +=  to_string(curr->val);

             curr = curr->next;
        }

        int i = 0; int j= s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }
};