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

// My brute force approach it might take worst complexity O(n^2)
//because we are finding the tail node for each node .
    void flatten(TreeNode* root) {
        
        if(root == NULL) return ;
        TreeNode* temp1 = root->left;
        TreeNode* temp2 = root->right;

        root->left = NULL;

        flatten(temp1);
        flatten(temp2);

        if(temp1!=NULL){
            root->right = temp1;

            while(temp1->right!=NULL){
                temp1 = temp1->right;
            }

            temp1->right = temp2;
        }
        else {
            root->right = temp2;
        }

    }
};