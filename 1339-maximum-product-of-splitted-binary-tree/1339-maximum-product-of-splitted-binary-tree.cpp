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
 long long  Postorder(TreeNode* root){
    long long sum = 0LL;
    if(root==nullptr) return 0LL;

   long long leftsum =  Postorder(root->left);
   long long rightsum =  Postorder(root->right);
    sum += leftsum + rightsum + root->val;
    return sum;
 }
 long long Post(TreeNode* root, long long&sum , long long&maxi){
    if(root==nullptr) return 0LL;
    long long leftsum = Post(root->left,sum,maxi);
    long long rightsum = Post(root->right,sum,maxi);
    long long z = leftsum+rightsum+root->val;
    maxi = max(maxi ,(1LL*z)*(sum-z));
    return leftsum+rightsum+root->val;
 }
class Solution {
public:
  long long const mod = 1e9+7;
    int maxProduct(TreeNode* root) {
        long long sum = Postorder(root);
        long long maxi = 0LL;
        Post(root,sum , maxi);
        return maxi%mod;
    }
};