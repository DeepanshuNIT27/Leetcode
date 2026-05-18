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

void allPaths(TreeNode* root,string temp , vector<string>&ans  ){

    if(temp.size()>=1)  temp += "->";
    
      temp +=  to_string(root->val);


    if(root->left == nullptr && root->right==nullptr){
        ans.push_back(temp);
        return ;
    }
    if(root->left!=nullptr) allPaths(root->left,temp,ans);
    if(root->right!=nullptr) allPaths(root->right,temp,ans);
}
    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string>ans;
       if(root == nullptr) return ans;
       string temp = "";
       allPaths(root,temp,ans);
       return ans;
         
    }
};