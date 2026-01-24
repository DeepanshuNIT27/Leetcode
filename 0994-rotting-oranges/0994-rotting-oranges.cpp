class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        int count = 0;
        int zero = 0;
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(grid[i][j]==2) {
                visited[i][j] = true;
                q.push({i,j});
            }
            else if(grid[i][j]==1) fresh++;
            
            else zero++;
            }
        }
        if(fresh==0) return 0;
        if(q.empty()) return -1;
        
        q.push({-1,-1});
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        while(!q.empty()){
          
          auto front = q.front();
          q.pop();
          int i = front.first;
          int j = front.second;
        if(i==-1 && j==-1){
            if(!q.empty()) 
            {q.push({-1,-1});
              count++;
            }
        }
        else{
          for(int k=0;k<4;k++){
            if( i+dx[k] >=0 && i+dx[k]<n && j+dy[k] >=0 && j+dy[k]<m && grid[i+dx[k]][j+dy[k]]==1 && visited[i+dx[k]][j+dy[k]]==false){
                q.push({i+dx[k],j+dy[k]});
                visited[i+dx[k]][j+dy[k]] = true;
                fresh--;
            }
          }

        }
    }
    if(fresh>0) return -1;
    return count;
    }
};