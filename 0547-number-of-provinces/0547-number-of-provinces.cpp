class Solution {
public:
//Using bfs
 void bfs(int src,vector<vector<int>>& isConnected,vector<bool>&visited ){
    visited[src] = true;
    queue<int>q;
    q.push(src);
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        for(int j=0;j<isConnected.size();j++){
            if(isConnected[curr][j]==1 && !visited[j]){
                visited[j] =true;
                q.push(j);
            }
        }
    }
 }
    int findCircleNum(vector<vector<int>>& isConnected) {
     vector<bool>visited(isConnected.size(), false);
     int provinces = 0;
     for(int i=0;i<isConnected.size();i++){
        if(!visited[i]){
            bfs(i,isConnected,visited);
            provinces++;
        }
     }
       return provinces; 
    }
};