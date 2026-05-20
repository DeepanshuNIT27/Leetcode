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

 // we will use the property of the binary tree 
 // time complexity of that sol is (log(n))^2
class Solution {
public:

int leftheight(TreeNode* root){

    if(root == nullptr) return 0;
    int count = 0;
    while(root){
        count++;
        root =  root->left;
    }
    return count ;
}

int rightheight(TreeNode* root){

    if(root == nullptr) return 0;
    int count = 0;
    while(root){
        count++;
        root = root->right;
    }
    return count;
}
    int countNodes(TreeNode* root) {
        
        if(root == nullptr) return 0;

        int left = leftheight(root->left);
        int right =rightheight(root->right);

        if(left == right) (1<<left) - 1 ;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};