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
    int maxDepth(TreeNode* root) {
        //BASE CASE;
        if(root == nullptr){
            return 0;
        }
        int leftsubtreeheight = maxDepth(root->left);
        int rightsubtreeheight= maxDepth(root->right);
        int maxi = max( leftsubtreeheight,rightsubtreeheight);
        int finalheigth = maxi+1;
        return finalheigth ;
    }
};