class Solution {
public:
//BFS
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        queue<pair<int,int>>q;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if( grid[i][j]==1 && (i==0 || j==0 || i==n-1 || j==m-1)){
                q.push({i,j});
                visited[i][j] = true;
            }
                }
            }
            int dx[] = {1,-1,0,0};
            int dy[] = {0,0,1,-1};
           
            while(!q.empty()){
            auto front = q.front();
            q.pop();
            for(int k=0;k<4;k++){
                int newx = front.first + dx[k];
                int newy = front.second + dy[k];
                if(newx>=0 && newx<n && newy>=0 && newy<m &&  visited[newx][newy]==false && grid[newx][newy]==1) {
                    q.push({newx,newy});
                    visited[newx][newy] = true;

                }
            }
            }
           int count = 0;
            for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
             if(grid[i][j]==1 && visited[i][j]==false) count++;
                }
            }
            return count ;
        
            }
};