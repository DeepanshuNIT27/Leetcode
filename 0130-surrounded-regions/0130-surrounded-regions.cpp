class Solution {
public:
bool dfs(int i , int j ,  vector<vector<bool>>&visited ,vector<vector<char>>& board , int n , int m,vector<pair<int,int>>& comp){
    visited[i][j] = true;
    comp.push_back({i,j});
    bool ans = true;
    if(i==0 || i==n-1 || j==0 || j==m-1) ans =  false;
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};
  
    for(int k=0;k<4;k++){
        if(i+dx[k]>=0 && i+dx[k]<n && j+dy[k]>=0 && j+dy[k]<m &&  board[i+dx[k]][j+dy[k]]=='O' && visited[i+dx[k]][j+dy[k]]==false){  bool temp =  dfs(i+dx[k],j+dy[k],visited,board,n,m,comp) ;
        if(!temp) ans = false;
        }
    }
return ans;
}
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              if(visited[i][j]==false && board[i][j]=='O'){
                 vector<pair<int,int>> comp;
              bool ans =   dfs(i,j,visited,board,n,m,comp);
              if(ans){
                for(auto&it:comp) board[it.first][it.second] = 'X';
              }
              }
            }
        }
    }
};