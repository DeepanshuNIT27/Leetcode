class Solution {
public:
bool dfs(int i ,vector<int>&visited ,  vector<int>&pathvisited , vector<int>&cycle , vector<vector<int>>& graph ){

    visited[i] = 1;
    pathvisited[i] = 1;
    cycle[i] = 0;
    
    for(auto nbr :graph[i] ){
        if(!visited[nbr]){

            if(dfs(nbr,visited,pathvisited,cycle,graph)) return true;
        }

        else if(pathvisited[nbr]) return true;
    }

    cycle[i] = 1;
    pathvisited[i] = 0;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int>ans;
        vector<int>visited(V,0);
        vector<int>pathvisited(V,0);
        vector<int>cycle(V,0);

        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,pathvisited,cycle,graph);
            }
        }
        for(int i=0;i<V;i++){
            if(cycle[i]==1) ans.push_back(i);
        }
        return ans;
    }
};