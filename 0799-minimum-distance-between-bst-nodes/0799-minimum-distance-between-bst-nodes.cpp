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
 void solve(TreeNode* &root , int &ans ,int &prev){
    if(root == NULL){
        return ;
    }
    //LNR
    solve(root->left,ans,prev);
    if(prev!=-1){
     int difference = abs(root->val - prev);
    ans = min(ans,difference);
    }
    prev = root->val;
    solve(root->right,ans,prev);
 }
    int minDiffInBST(TreeNode* root) {
       int ans = INT_MAX;
       int prev = -1;
       solve(root,ans,prev);
       return ans;
        
    }
};