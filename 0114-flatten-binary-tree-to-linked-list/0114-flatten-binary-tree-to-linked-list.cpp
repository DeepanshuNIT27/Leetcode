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
// THIS IS A RECURSIVE APPROACH HAVING THE TIME COMPLEXITY O(N) AND
// SPACE COMPLEXITY O(N);

TreeNode* solve(TreeNode* root){

    if(root == NULL) return NULL;

    TreeNode* leftTail = solve(root->left);
    TreeNode* rightTail = solve(root->right);

    TreeNode* left = root->left;
    TreeNode * right = root->right;

    root->left = NULL;
    if(left){
        root->right = left;
        leftTail->right = right;
    }
    else{
        root->right = right;
    }

    if(rightTail) return rightTail;
    if(leftTail) return leftTail;

    return root;
}
    void flatten(TreeNode* root) {
        solve(root);
    }
};