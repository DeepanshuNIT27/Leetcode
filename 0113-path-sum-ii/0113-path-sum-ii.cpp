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
void solve(TreeNode* root ,int targetSum ,int sum ,vector<int>output ,vector<vector<int>>&ans){
    if(root == NULL){
        return ;
    }
    sum += root->val;
    output.push_back(root->val);
    if(root->left == NULL && root->right== NULL){
        if(sum == targetSum) {
            ans.push_back(output);
            return ;
        }
    
        
    }
    solve(root->left,targetSum,sum,output,ans);
    solve(root->right,targetSum,sum,output,ans);
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>output;
        int sum = 0;
        solve(root,targetSum,sum,output,ans);
        return ans;
        
    }
};