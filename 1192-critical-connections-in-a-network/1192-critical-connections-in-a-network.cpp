class Solution {
private :
  int timer = 1;
public:
void dfs( unordered_map<int,list<int>>&Adj, vector<int>&visited, vector<int>&tin, vector<int>&low , int parent , int node, vector<vector<int>>&bridge){

    visited[node] = true;
    tin[node] = low[node] = timer ;
    timer++;

    for(auto it: Adj[node]){
        if(it == parent) continue;
        if(!visited[it]){
            dfs(Adj,visited,tin,low,node,it,bridge);
            low[node] = min(low[node],low[it]);

            if(low[it] > tin[node]){
              bridge.push_back({it,node});
            }
        }
        else{
              low[node] = min(low[node],low[it]);
        }
    }

}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>>Adj;
        for(auto connection : connections){
            Adj[connection[0]].push_back(connection[1]);
            Adj[connection[1]].push_back(connection[0]);
        }
        vector<int>tin(n);
        vector<int>low(n);
        vector<int>visited(n,false);
        vector<vector<int>>bridge;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(Adj,visited,tin,low,-1,i,bridge);
            }
        }
return bridge;
    }
};