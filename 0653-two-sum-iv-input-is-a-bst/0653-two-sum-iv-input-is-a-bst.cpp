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
void traversal(TreeNode* root, unordered_map<int,int>&mp){

    if(root == NULL) return ;

    traversal(root->left,mp);
    mp[root->val]++;
    traversal(root->right,mp);
}

bool solve(TreeNode* root, int k , unordered_map<int,int>&mp ){

    if(root==NULL) return false;

    int d =  k - root->val;
    if(mp.find(d)!=mp.end() && d!= root->val) return true;

    return solve(root->left,k,mp) || solve(root->right,k,mp);

}
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>mp;
        traversal(root,mp);

        return solve(root,k,mp);
    }
};