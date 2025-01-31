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

 TreeNode* constructTree(vector<int>& preorder,vector<int>& inorder,unordered_map<int,int>&map,int &preIndex, int instart,int inEnd, int size){

    if(preIndex >= size){
        return NULL;
    }
    if(instart > inEnd){
        return NULL;
    }
    int element = preorder[preIndex];
    preIndex++;
    TreeNode* root = new TreeNode(element);
    int index = map[element];
    root->left = constructTree(preorder,inorder,map,preIndex,instart,index-1,size);
     root->right = constructTree(preorder,inorder,map,preIndex,index+1,inEnd,size);
    return root;

 }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
  int preIndex = 0;
  int inStart = 0;
  int inEnd = inorder.size()-1;
  int size = preorder.size();
  unordered_map<int,int>map;
    for(int i=0 ;i<inorder.size();i++){
        map[inorder[i]] = i ;
    }
  return constructTree(preorder,inorder,map,preIndex,inStart,inEnd,size);
    }
};