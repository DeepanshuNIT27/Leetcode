class Solution {
public:
void dfs(vector<vector<int>>& isConnected, vector<bool>&visited, int i){
    visited[i] = true;
   for(int j = 0;j<isConnected.size();j++){
    if(isConnected[i][j]==1 && visited[j]==false) dfs(isConnected,visited,j);
   }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        //adjacency list 
        int n = isConnected.size();
        vector<bool>visited(n+1,false);
        int count = 0;
        for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(isConnected,visited,i);
            count++;
        }
        }
        return count;
    }
};