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

TreeNode* solve(int &i ,vector<int>& preorder, vector<int>inorder,int instart , int inend ,   unordered_map<int,int>&mp ){

    if(i>= preorder.size()) return NULL;
   
    if(instart > inend) return NULL;

    TreeNode * temp = new TreeNode(preorder[i]);
    int element = mp[preorder[i]];
    i++;
    temp->left = solve(i,preorder,inorder,instart,element-1,mp);
    temp->right = solve(i,preorder,inorder,element+1,inend,mp);

    return temp;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int>inorder = preorder;
        sort(inorder.begin(),inorder.end());
        int i = 0;
        int instart = 0;
        int inend = n-1;

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) {
            mp[inorder[i]] = i;
        }

        return solve(i,preorder,inorder , instart , inend,mp);


    }
};