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
 class Info{
public:
 long long minval;
 long long maxval;
 bool isBst;
 };
class Solution {
public:
Info solve(TreeNode* root,bool &ans){
    if(root== NULL){
        Info temp;
        temp.minval = LONG_MAX;
        temp.maxval = LONG_MIN;
        temp.isBst = true;
        return temp;
    }
    Info leftans = solve(root->left,ans);
    Info rightans = solve(root->right,ans);
    Info currans;
     currans.minval = min((long long)leftans.minval,(long long)root->val);
    currans.maxval = max((long long)rightans.maxval,(long long)root->val);
   currans.isBst = (root->val> leftans.maxval && root->val < rightans.minval && leftans.isBst && rightans.isBst);
   if(!currans.isBst){
    ans = false;
   }
   return currans;

}
    bool isValidBST(TreeNode* root) {
        bool ans = true;
        solve(root,ans);
        return ans;
        
    }
};