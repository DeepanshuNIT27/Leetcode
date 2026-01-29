class Solution {
public:
  bool dfs(int i, int j , vector<vector<bool>>&visited,vector<vector<char>>& grid, int dx[] , int dy[] , pair<int,int>p,int n , int m){
 
 visited[i][j] = true;
 for(int k=0;k<4;k++){
    int newx = i + dx[k] ;
    int newy = j + dy[k] ;

    if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==grid[i][j] && !visited[newx][newy]){
       if(dfs(newx,newy,visited,grid,dx,dy,{i,j},n,m)) return true;
    }
    else if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==grid[i][j] && visited[newx][newy]==true && newx!=p.first && newy!=p.second) {return true;}
 }
 return false; 
  }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                  if(dfs(i,j,visited,grid,dx,dy,{-1,-1},n,m))return true;
                }
            }
        }
        return false;

    }
};