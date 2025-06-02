class Solution {
public:
bool topSort( unordered_map<int,list<int>>&adj, int n){
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
        st.push(frontNode);
        for(auto nbr:adj[frontNode]){
            indegree[nbr]--;
            if(indegree[nbr]==0){
                q.push(nbr);
            }
        }
    }
    if(st.size()==n) return true;
    return false;

}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>>adj;
        for(int i=0;i<prerequisites.size();i++){
            auto it = prerequisites[i];
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        bool ans = topSort(adj, numCourses);
   return ans;
    }
};