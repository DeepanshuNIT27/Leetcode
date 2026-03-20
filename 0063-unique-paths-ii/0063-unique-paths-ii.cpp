class Solution {
public:
bool isSafe(int i , int j , int m , int n,vector<vector<int>>& obstacleGrid){
    if(i>=0 && i<m && j>=0 && j<n && obstacleGrid[i][j]==0) return true;
    return false;
}
//Recursion
int solveRec(int i, int j , int m , int n,vector<vector<int>>& obstacleGrid){
     if(i==m-1 && j==n-1) return 1;
     if(i>=m || j>=n) return 0;
     int ans = 0;
     int dx[] = {0,1};
     int dy[] = {1,0};
     for(int k=0;k<2;k++){
        if(isSafe(i+dx[k] , j+dy[k],m,n,obstacleGrid)){
           ans += solveRec(i+dx[k] , j+dy[k] , m , n,obstacleGrid);

        }
     }
     return ans;
}
//Memoization soln 
int solveMemo(int i, int j , int m , int n, vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
     if(i==m-1 && j==n-1) return 1;
     if(i>=m || j>=n) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     int ans = 0;
     int dx[] = {0,1};
     int dy[] = {1,0};
     for(int k=0;k<2;k++){
        if(isSafe(i+dx[k] , j+dy[k],m,n,obstacleGrid)){
           ans += solveMemo(i+dx[k] , j+dy[k] , m , n,dp,obstacleGrid);

        }
     }
     dp[i][j] =  ans;
     return dp[i][j];
}
// Tabulation 
int solveTab(int m , int n,vector<vector<int>>& obstacleGrid ){
vector<vector<long long >>dp(m+1,vector<long long>(n+1,0));
  dp[m-1][n-1] = 1;

  for(int i=m-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
     if(i == m-1 && j==n-1) continue;
     long long  ans = 0LL;
     int dx[] = {0,1};
     int dy[] = {1,0};
     for(int k=0;k<2;k++){
        if(isSafe(i+dx[k] , j+dy[k],m,n,obstacleGrid)){
           ans += dp[i+dx[k]][j+dy[k]];
        }
     }
      dp[i][j] = ans;
    }
   
  }
  return (int)dp[0][0];
}

// space optimizatio
int solveSO(int m , int n,vector<vector<int>>& obstacleGrid ){
vector<long long >next(n+1,0);
vector<long long >curr(n+1,0);
  next[n-1] = 1;

  for(int i=m-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
     if(i == m-1 && j==n-1) {
        curr[j] = 1;
        continue;
     }
     long long  ans = 0;
     int dx[] = {0,1};
     int dy[] = {1,0};
     for(int k=0;k<2;k++){
        if(isSafe(i+dx[k] , j+dy[k],m,n,obstacleGrid )){
         if(dx[k]==0)  ans += curr[j+1];
         else ans += next[j];
        }
     }
      curr[j] = ans;
    }
    next = curr;
   
  }
  return curr[0];
}



    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
       
        int m = obstacleGrid.size();
        int n  = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 ||obstacleGrid[m-1][n-1]==1 ) return 0;

         // Recursion 
       // return solveRec(0,0,m,n,obstacleGrid);

       // Memoization
        //  vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return solveMemo(0,0,m,n,dp,obstacleGrid);

        //  Tabulation 
     // return solveTab(m,n,obstacleGrid);

    
      //space optimization
      return solveSO(m,n,obstacleGrid);
    }
};