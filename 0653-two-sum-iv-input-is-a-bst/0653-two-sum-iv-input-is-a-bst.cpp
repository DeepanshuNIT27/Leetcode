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
   void inordertraversal(TreeNode* root ,vector<int>&inorder){
    if(root == NULL){
        return ;
    }
    //LNR;
    inordertraversal(root->left, inorder);
    inorder.push_back(root->val);
     inordertraversal(root->right, inorder);
   }

   bool check(vector<int>&arr, int k){
    int n = arr.size();
    int s = 0;
    int e = n-1;
    while(s<e){
        if(arr[s]+arr[e] == k){
            return true;
        }
        if(arr[s]+arr[e] <k){
            s++;
        }
        if(arr[s]+arr[e] > k){
            e--;
        }

    }
    return false;
   }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inorder;
        inordertraversal(root,inorder);
        bool ans = check(inorder,k);
        return ans;
    }
};