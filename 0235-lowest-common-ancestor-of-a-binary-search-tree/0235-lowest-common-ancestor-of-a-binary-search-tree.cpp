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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        //CASE 1 BOTH P & Q LEFT ME HO
        if(p->val< root->val&& q->val< root->val){
            TreeNode* leftans = lowestCommonAncestor(root->left,p,q);
            if(leftans!=NULL){
                return leftans;
            }
        }
        // CASE 2 BOTH P & Q RIGHT SIDE ME HO
        if(p->val>root->val&& q->val>root->val){
         TreeNode* rightans = lowestCommonAncestor(root->right,p,q);
         if(rightans!= NULL){
            return rightans;
         }
        }
        // CASE 3 P LEFT ME HO Q RIGHT ME HO
        //CASE 4 P RIGHT ME HO Q LEFT ME HO
        return root;
        
    }
};