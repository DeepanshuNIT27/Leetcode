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
  int getMax(TreeNode* root){
    if(root == NULL){
        return -1;
    }
    while(root->right!=NULL){
        root = root->right;
    }
    return root->val;
  }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root ==  NULL){
            return NULL;
        }
        if(root->val == key){
            // 4 CASE.
            //1.Leaf root/ no child;
            if(root->left== NULL && root->right==NULL ){
                delete root;
                return NULL;
            }
            //2.root with only left child;
            if(root->left!=NULL && root->right==NULL){
                
                TreeNode* leftchild = root->left;
                root->left = NULL;
                delete root;
                return leftchild;
            }
            //3.root with only right child;
            if(root->left==NULL && root->right!=NULL){
                TreeNode* rightchild = root->right;
                root->right= NULL;
                delete root;
                return rightchild;
            }
            //4. root with both child;
            if(root->left!= NULL && root->right!=NULL){
                //JUST MEANS AND JUST MAX DONO SE KE SKTE HAI 
                //ye copy se ho rha .
                // int maxval = getMax(root->left);
                // root->val = maxval;
                // root->left = deleteNode(root->left,maxval);
                // return root;

                //inplace aise hoga 
                auto rscan = root->right;
                while(rscan->left){
                    rscan = rscan->left;
                }
                rscan->left = root->left ;
                auto rightchild = root->right;
                delete root;
                return rightchild;
            }
            
        }
        else{
            if(key< root->val){
                root->left = deleteNode(root->left ,key);
            }
            else{
                root->right = deleteNode(root->right ,key);
            }
        }
        return root;
    }
};