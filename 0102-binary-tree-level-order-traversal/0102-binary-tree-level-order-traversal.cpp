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
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>>v;
        if(root==nullptr) return v;

        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr);

        vector<int>temp;

        while(!q.empty()){
           
           auto front = q.front();
           q.pop();

           if(front==nullptr){
            v.push_back(temp);
            temp.clear();
              if(!q.empty()) q.push(nullptr);
           }

           else{
               temp.push_back(front->val);

              if(front->left!=nullptr) q.push(front->left);
              if(front->right!=nullptr) q.push(front->right);
            
           }

        }
       
        return v;
        
    }
};