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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int getLength(ListNode*&head){
    ListNode* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
TreeNode* solve(ListNode*&head ,int n){
    if(n<=0 || head== NULL){
        return NULL;
    }
    TreeNode* leftsubtree = solve(head, n/2);
    TreeNode* root = new TreeNode(head->val);
    head = head->next;
    root->left = leftsubtree;
    TreeNode* rightsubtree = solve(head, n-n/2-1);
    root->right = rightsubtree;
    return root;
}
    TreeNode* sortedListToBST(ListNode* head) {
        int  n = getLength(head);
        TreeNode* root= solve(head,n);
        return root;
        
    }
};