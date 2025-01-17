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
     int getHeight(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        int maxi = max(left , right);
        int finalHeigth = maxi + 1 ;
        return finalHeigth ;
     }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0 ;
        }
        int option1 = diameterOfBinaryTree(root->left);
        int option2 = diameterOfBinaryTree(root->right);
        int option3 = getHeight(root->left)+ getHeight(root->right);
        return max(option1 , max(option2,option3));
    }
};