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
    vector<int> preorderTraversal(TreeNode* root) {
        //ITERATIVE PREORDER USING THE STACK 
        vector<int>v;
        if(root == nullptr) return v;
        stack<TreeNode*>st;
        st.push(root);

        while(!st.empty()){
            auto front = st.top();
            st.pop();

            v.push_back(front->val);
            if(front->right!=nullptr) st.push(front->right);
            if(front->left!=nullptr) st.push(front->left); 
        }

        return v;
    }
};