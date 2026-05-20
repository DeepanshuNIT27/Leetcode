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

// it is using simple dfs O(N)
class Solution {
public:

int totalNode(TreeNode* root){

    if(root == nullptr) return 0;

    int leftNode = totalNode(root->left);
    int rightNode = totalNode(root->right);

    return 1 + leftNode + rightNode;
}
    int countNodes(TreeNode* root) {
        return totalNode(root);
    }
};