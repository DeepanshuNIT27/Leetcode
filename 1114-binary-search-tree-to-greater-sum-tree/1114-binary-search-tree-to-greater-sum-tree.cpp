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
 void mapping(unordered_map<int,int>&map,vector<int>&v,vector<int>&presum){
    map[v[0]] = presum[presum.size()-1];
    for(int i=1 ;i<v.size();i++){
        map[v[i]] = presum[presum.size()-1] - presum[i-1];
    }
 }
 TreeNode* finalTraversal(TreeNode* root , unordered_map<int,int>&map){
    if(root == NULL){
        return NULL;
    }
    finalTraversal(root->left,map);
    finalTraversal(root->right ,map);
    root->val = map[root->val];
    return root;
 }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>v;
        inorder(root,v);
        vector<int>presum(v.size());
        unordered_map<int,int>map;
        presum[0] = v[0];
        for(int i=1 ;i< v.size();i++){
          presum[i] = presum[i-1] + v[i];
        }
        mapping(map,v,presum);
return finalTraversal(root,map);
    }
};