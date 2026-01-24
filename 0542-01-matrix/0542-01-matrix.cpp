class Solution {
public:
//BFS LAGAO SARA DISTANCE BY DISTANCE EXPLORE KRO DFS WILL NOT WORK HERE
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
       int n = mat.size();
       int m = mat[0].size();
       vector<vector<bool>>visited(n,vector<bool>(m,false));
       vector<vector<int>>ans(n,vector<int>(m,0));
       queue<pair<pair<int,int>,int>>q;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==0) {
                q.push({{i,j},0});
                visited[i][j] = true;
            }
        }
       }
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            auto p = front.first;
            auto d = front.second;
            ans[p.first][p.second] = d;
            for(int k=0;k<4;k++){
                if(p.first+dx[k]>=0 && p.first+dx[k]<n &&p.second+dy[k]>=0 && p.second+dy[k]<m && visited[p.first+dx[k]][p.second+dy[k]]==false ){
                   visited[p.first+dx[k]][p.second+dy[k]] = true;
                   q.push({{p.first+dx[k],p.second+dy[k]},d+1});
                }
            }
        }
       return ans;
    }
};