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
 void LevelOder(TreeNode* root, int &n){
    if(root == nullptr) return;
    queue<TreeNode*>q;
    q.push(root);
    q.push(nullptr);
    long long sum = INT_MIN;
    long long tempsum = 0;
    int count = 0;
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        if(front==nullptr){
           count++;
           if(tempsum>sum){
                n = count;
                sum = tempsum;
           }
           tempsum = 0LL;
           if(!q.empty()) q.push(nullptr);
        }
        else{
            tempsum += front->val;
            if(front->left!=nullptr) q.push(front->left);
            if(front->right!=nullptr) q.push(front->right);
        }

    }
 }
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int n = 0;
        LevelOder(root,n);
        return n;
    }
};