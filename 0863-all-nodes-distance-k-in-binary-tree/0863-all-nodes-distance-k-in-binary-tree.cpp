/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
void Traversal(TreeNode* root,unordered_map<int,vector<int>>&Adj ){

    if(root->left==nullptr && root->right==nullptr) return ;

    if(root->left) {
        Adj[root->val].push_back(root->left->val);
        Adj[root->left->val].push_back(root->val);
        Traversal(root->left,Adj);
    }

    if(root->right){
        Adj[root->val].push_back(root->right->val);
        Adj[root->right->val].push_back(root->val);
        Traversal(root->right,Adj);
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        if(!root) return ans;

        unordered_map<int,vector<int>>Adj;
        Traversal(root,Adj);

        int n = Adj.size();

        queue<pair<int,int>>q;
        q.push({target->val,0});
        vector<bool>visited(n+1,false);
        visited[target->val] = true;

        while(!q.empty()){
            
            auto front = q.front();
            int node = front.first;
            int dist = front.second;
            q.pop();
            visited[node] = true;
            if(dist>k) continue;
            if(dist == k) ans.push_back(node);

            for(auto&it:Adj[node]){
                if(!visited[it]) q.push({it,dist+1});
            }
        }
        return ans;
    }
};