class Solution {
public:
void topSort( unordered_map<int,list<int>>&adj, int n,vector<int>&ans){
    //creating indegree
    unordered_map<int,int>indegree;
    for(auto a: adj){
        for(auto b : a.second){
            indegree[b]++;
        }
    }
    //maintaining iniatal state
    queue<int>q;
    stack<int>st;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    //main logic
    while(!q.empty()){
        auto frontNode = q.front();
        q.pop();
       ans.push_back(frontNode);
        for(auto nbr:adj[frontNode]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }
    }
    //cycle check
    if(ans.size()!=n){
        ans.clear();
    }
    

}
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         unordered_map<int,list<int>>adj;
        for(int i=0;i<prerequisites.size();i++){
            auto it = prerequisites[i];
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        vector<int>ans;
         topSort(adj, numCourses,ans);
         return ans;
    }
    
};