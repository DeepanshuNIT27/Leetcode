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

TreeNode* solve(TreeNode* root, int key){

    if(root == NULL) return NULL;

    // SEARCH PART 
    if(root->val > key){
        root->left = solve(root->left,key);
    }
    else if(root->val < key){
        root->right = solve(root->right,key);
    }
    // Node mil gya 
    else {

        // 0 child 
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        // 1 Child 

        if(root->left == NULL){
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        if(root->right == NULL){
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        //2 Child 
        TreeNode* temp = root->right;
        while(temp->left){
            temp  = temp->left;
        }
        // replace the value 
        root->val = temp->val;
        // delete dublicate node
        root->right = solve(root->right,temp->val);

    }
    return root;

}
    TreeNode* deleteNode(TreeNode* root, int key) {
        return solve(root,key);
    }
};