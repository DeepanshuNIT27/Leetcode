class Solution {
public:

 // using dfs
 void dfs(int src,vector<vector<int>>& isConnected,vector<bool>&visited){
    visited[src] = true;
     for(int j=0;j<isConnected.size();j++){
            if(isConnected[src][j]==1 && !visited[j]){
                dfs(j,isConnected,visited);
            }
     }
 }

    int findCircleNum(vector<vector<int>>& isConnected) {
     vector<bool>visited(isConnected.size(), false);
     int provinces = 0;
     for(int i=0;i<isConnected.size();i++){
        if(!visited[i]){
            dfs(i,isConnected,visited);
            provinces++;
        }
     }
       return provinces; 
    }
};