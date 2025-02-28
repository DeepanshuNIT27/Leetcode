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
//METHOD-1 ; LAMBA METHOD
//  class Info{
// public:
//  long long minval;
//  long long maxval;
//  bool isBst;
//  };
// class Solution {
// public:
// Info solve(TreeNode* root,bool &ans){
//     if(root== NULL){
//         Info temp;
//         temp.minval = LONG_MAX;
//         temp.maxval = LONG_MIN;
//         temp.isBst = true;
//         return temp;
//     }
//     Info leftans = solve(root->left,ans);
//     Info rightans = solve(root->right,ans);
//     Info currans;
//      currans.minval = min((long long)leftans.minval,(long long)root->val);
//     currans.maxval = max((long long)rightans.maxval,(long long)root->val);
//    currans.isBst = (root->val> leftans.maxval && root->val < rightans.minval && leftans.isBst && rightans.isBst);
//    if(!currans.isBst){
//     ans = false;
//    }
//    return currans;

// }
//     bool isValidBST(TreeNode* root) {
//         bool ans = true;
//         solve(root,ans);
//         return ans;
        
//     }
// };
// METHOD-2 RANGE CHECK METHOD;
class Solution{
    public:
    bool validate(TreeNode* root ,long long lb , long long ub){
        if(!root) return true;

        bool iscurrnodeinrange = root->val > lb && root->val <ub;

        bool isleftbst = validate(root->left ,lb , root->val);
        bool isrightbst = validate(root->right ,root->val ,ub);
        return iscurrnodeinrange &&isleftbst && isrightbst;
    }
    bool isValidBST(TreeNode* root){
        long long lb = LONG_MIN;
        long long ub = LONG_MAX;
        return validate(root,lb,ub);
    }
};