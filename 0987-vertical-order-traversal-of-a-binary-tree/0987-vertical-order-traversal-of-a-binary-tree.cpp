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

void  vertiTraversal(TreeNode* root, int row , int column , map<int,vector<pair<int,int>>>&mp){
    if(root == nullptr) return ;

    mp[column].push_back({row,root->val});

    vertiTraversal(root->left,row+1,column-1,mp);
    vertiTraversal(root->right,row+1,column+1,mp);
}
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>mp;
        vector<vector<int>>ans;
        vertiTraversal(root,0,0,mp);
        for(auto&it:mp){
            auto &temp = it.second;
            sort(temp.begin(),temp.end());
            vector<int>v;
            for(int i=0;i<temp.size();i++){
                v.push_back(temp[i].second);
            }
            ans.push_back(v);
        }
        return ans;
    }
};