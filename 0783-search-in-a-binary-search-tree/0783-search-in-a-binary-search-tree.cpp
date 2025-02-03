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
 TreeNode* searchinBST(TreeNode* root , int val){
    if(root== NULL){
        return NULL ;
    }
    if(root->val == val){
        return root;
 }
 else{
    if(val< root->val){
       TreeNode* leftans = searchinBST(root->left,val);
       if(leftans!=NULL){
        return leftans;
       }
    }
    else{
       TreeNode* rightans = searchinBST(root->right,val);
       if(rightans!=NULL){
        return rightans;
       }
    }
 }
 return NULL;
 }
    TreeNode* searchBST(TreeNode* root, int val) {
     return searchinBST(root,val);
        
    }
};