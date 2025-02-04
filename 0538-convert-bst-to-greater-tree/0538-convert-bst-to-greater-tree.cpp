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
 void inorder(TreeNode*root ,  vector<int>&v){
    if(root == NULL){
        return ;
    }
    inorder(root->left,v);
    v.push_back(root->val);
     inorder(root->right,v);
 }
  void updatedTree(TreeNode* root ,vector<int>&v, int &index){
    if(root == NULL){
        return ;
    }
    //LNR
    updatedTree(root->left,v,index);
    root->val= v[index];
    index++;
    updatedTree(root->right, v , index);
  }
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        if(root->left == NULL && root->right == NULL){
            return root;
        }
        vector<int>v;
        inorder(root,v);
        int n = v.size()-1;
        int sum = 0;
        for(int i=n ;i>=0;i--){
            sum = sum + v[i];
            v[i] = sum;
        }
        int index = 0;
        updatedTree(root,v,index);
        return root;

    }
};