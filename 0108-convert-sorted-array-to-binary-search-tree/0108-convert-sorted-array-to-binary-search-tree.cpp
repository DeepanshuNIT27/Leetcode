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
   TreeNode* solve(vector<int>&nums ,int s ,int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    int element = nums[mid];
    TreeNode* root = new TreeNode(element);
    root->left = solve(nums,s,mid-1);
    root->right = solve(nums,mid+1,e);
    return root;
   }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        TreeNode* ans = solve(nums,s,e);
        return ans;
        
    }
};