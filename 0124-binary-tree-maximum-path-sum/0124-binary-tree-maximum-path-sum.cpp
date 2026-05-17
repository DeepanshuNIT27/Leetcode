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

int pathSum(TreeNode* root, int &ans){

    if(root == nullptr) return 0;
    
  
    int lsum = max(0,pathSum(root->left,ans));
    int rsum = max(0,pathSum(root->right,ans));

    ans = max(ans, (root->val + lsum+rsum));
    return root->val + max(lsum,rsum);
}
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
         pathSum(root,ans);
         return ans ;
    }
};