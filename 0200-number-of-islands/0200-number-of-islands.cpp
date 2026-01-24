class Solution {
public:
 //BFS
 void BFS(int y , int z ,vector<vector<char>>& grid, vector<vector<bool>>&visited ){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int,int>>q;
    q.push({y,z});
    visited[y][z] = true;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
     while(!q.empty()){
     auto front = q.front();
     int i = front.first;
     int j = front.second;
     q.pop();
     for(int k=0;k<4;k++){
        if(i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k] < m &&  grid[i+dx[k]][j+dy[k]]=='1' && visited[i+dx[k]][j+dy[k]]==false )  {
            q.push({i+dx[k] , j+dy[k]});
            visited[i+dx[k]][j+dy[k]] = true;
        }
     }
    }
 }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='0' || visited[i][j]==true) continue;
                BFS(i,j,grid,visited);
                count++;
            }
        }
        return count;
    }
};