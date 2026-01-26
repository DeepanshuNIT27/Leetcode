class Solution {
public:
//DFS
bool dfs(int i , int j ,vector<vector<bool>>&visited,vector<vector<int>>& grid, int &count ,int n , int m ){
     bool ans = true;
    visited[i][j] = true;
    if(i==0 || i==n-1 || j==0 || j==m-1) ans = false;

    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    for(int k = 0;k<4;k++){
        int newx = i + dx[k];
        int newy = j + dy[k];
        if(newx>=0 && newx<n && newy>=0 && newy<m && visited[newx][newy]==false && grid[newx][newy]==1){
            count += 1;
            bool temp = dfs(newx, newy , visited,grid,count,n,m);
            if(!temp) ans = temp;
        }
    }
    return ans;
}
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j]==false  &&  grid[i][j]==1){
                    int count  = 1;
                    if(dfs(i,j,visited,grid,count,n,m)){
                        ans += count;
                    }
                }
            }
        }
        return ans;
    }
};