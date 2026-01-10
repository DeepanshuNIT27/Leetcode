class Solution {
public:
//DFS
void dfs(vector<vector<char>>& grid, vector<vector<bool>>&visited, int i , int j){
    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size()) return ;
    if(visited[i][j]==true ||  grid[i][j]=='0') return ;

    visited[i][j] = true;
    dfs(grid,visited,i+1,j);
    dfs(grid,visited,i-1,j);
    dfs(grid,visited,i,j+1);
    dfs(grid,visited,i,j-1);

}
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'  && visited[i][j]==false){
                    dfs(grid,visited,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};