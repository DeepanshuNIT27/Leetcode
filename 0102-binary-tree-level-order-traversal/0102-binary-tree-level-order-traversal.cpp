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
void levelorder(TreeNode* root, vector<vector<int>>&v,vector<int>ans){
    if(root == NULL){
        return ;
    }
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        auto element = q.front();
        q.pop();
        if(element == NULL){
         v.push_back(ans);
         ans.clear();
         if(!q.empty()){
            q.push(NULL);
         }
        }
        else{
            ans.push_back(element->val);
            if(element->left!=NULL){
                q.push(element->left);
            }
            if(element->right!=NULL){
                q.push(element->right);
            }
        }
    }
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        vector<int>ans;
        levelorder(root,v,ans);
        return v;
    }
};