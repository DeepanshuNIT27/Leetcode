/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

TreeNode* LCA(TreeNode* root,TreeNode* p,TreeNode* q){

    if(root == nullptr) return nullptr;

    if(root->val == q->val) return q;
    if(root->val == p->val) return p;

    TreeNode* left = LCA(root->left,p,q);
    TreeNode* right = LCA(root->right,p,q);

    if(left==nullptr && right ==nullptr) return nullptr;
    else if(left==nullptr) return right;
    else if(right==nullptr) return left;
    return root;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
      return   LCA(root,p,q);
       
    }
};