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
 int heightdfs(TreeNode* root){
    if(root==nullptr) return 0;
    int ans1 = heightdfs(root->left);
    int ans2 = heightdfs(root->right);
    return max(ans1,ans2) + 1; 
 }
 bool solvedfs(TreeNode* root,TreeNode*&temp, int &height , int x){
    if(root==nullptr) return false;
    if(root->left==nullptr && root->right==nullptr && height == x){
        temp = root;
        return true;
    }
    bool ans1 = solvedfs(root->left,temp,height,x+1);
    bool ans2 = solvedfs(root->right,temp,height,x+1);
    if(ans1 && ans2) temp = root;
    return ans1 || ans2;
 }
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int height = heightdfs(root);
        TreeNode* temp = root;
        solvedfs(root,temp,height,1);
        return temp;
    }
};