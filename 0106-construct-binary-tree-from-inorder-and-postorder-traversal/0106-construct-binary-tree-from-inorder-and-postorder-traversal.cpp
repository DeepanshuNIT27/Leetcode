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

   TreeNode* solve(vector<int>& inorder,vector<int>& postorder,unordered_map<int,int>&map,int inStart , int inEnd , int &postIndex){
        if(postIndex<0){
            return NULL;
        }
        if(inStart>inEnd){
            return NULL;
        }
        int element = postorder[postIndex];
        postIndex--;
        TreeNode* root = new TreeNode(element);
        int index = map[element];

        root->right = solve(inorder,postorder,map,index+1,inEnd,postIndex);
         root->left = solve(inorder,postorder,map,inStart,index-1,postIndex);
        return root;

   }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>map;
        int inStart = 0;
        int inEnd = inorder.size()-1;
        int size = postorder.size();
        int postIndex = size - 1;
        for(int i=0 ;i<inorder.size();i++){
            map[inorder[i]] = i;
        }
     
     return    solve(inorder,postorder,map,inStart,inEnd,postIndex);

        
    }
};