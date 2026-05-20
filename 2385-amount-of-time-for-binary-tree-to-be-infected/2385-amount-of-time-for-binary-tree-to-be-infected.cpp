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

void Traversal(TreeNode* root, unordered_map<int,vector<int>>&Adj){
    if(root->left==nullptr && root->right==nullptr) return ;

    if(root->left){
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
    int amountOfTime(TreeNode* root, int start) {
        if(!root) return 0;

        unordered_map<int,vector<int>>Adj;
        Traversal(root,Adj);
        int  n = Adj.size();
        unordered_map<int,bool>visited;

        int ans = 0 ;

        queue<pair<int,int>>q;
        q.push({start,0});

        while(!q.empty()){

            auto front = q.front();
            int node = front.first;
            int min = front.second;
            visited[node] = true;
            q.pop();

            ans = max(ans,min);

            for(auto&it:Adj[node]){
                if(!visited[it]) q.push({it,min+1});
            }
        }
return ans;
    }
};