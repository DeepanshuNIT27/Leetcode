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
void solve(TreeNode* root , int val ) {

    if(root->left == nullptr && root->val > val) {
        TreeNode*temp = new TreeNode(val);
        root->left = temp;
        return ;
    }

   else if(root->right == nullptr && root->val<val){
        TreeNode*temp = new TreeNode(val);
        root->right = temp;
        return ;
   }

   if(root->val<val) solve(root->right,val);
   if(root->val>val) solve(root->left,val);
}
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) {
             TreeNode*temp = new TreeNode(val);
             return temp;
        }
        solve(root,val);
        return root;
    }
};