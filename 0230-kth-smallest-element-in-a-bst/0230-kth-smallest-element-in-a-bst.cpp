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

// 1.st solution// O(n) , O(n);
// class Solution {
// public:
// void inorder(TreeNode* root ,vector<int>&v){
//     if(root== NULL){
//         return ;
//     }
//     //NLR
//     inorder(root->left,v);
//     v.push_back(root->val);
//     inorder(root->right,v);
// }
//     int kthSmallest(TreeNode* root, int k) {
//         vector<int>v;
//         inorder(root,v);
//         return v[k-1];
        
//     }
// };
// 2ns solution o(n) ,O(1);
class Solution {
public:
void inorder(TreeNode*root , int k ,int & count,int &value){
    if(root==NULL){
        return ;
    }
    
    inorder(root->left,k,count,value);
    count++;
    if(count == k){
        value = root->val;
        return;
    }
    inorder(root->right,k,count,value);
}
int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int value = 0;
  inorder(root,k,count,value);
  return value;
}

};