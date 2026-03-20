class Solution {
public:
bool isSafe(int i , int j , int m , int n){
    if(i>=0 && i<m && j>=0 && j<n) return true;
    return false;
}
//Recursion soln 
int solveRec(int i, int j , int m , int n){
     if(i==m-1 && j==n-1) return 1;
     if(i>=m || j>=n) return 0;
     int ans = 0;
     int dx[] = {0,1};
     int dy[] = {1,0};
     for(int k=0;k<2;k++){
        if(isSafe(i+dx[k] , j+dy[k],m,n)){
           ans += solveRec(i+dx[k] , j+dy[k] , m , n);

        }
     }
     return ans;
}
//Memoization soln 
int solveMemo(int i, int j , int m , int n, vector<vector<int>>&dp){
     if(i==m-1 && j==n-1) return 1;
     if(i>=m || j>=n) return 0;
     if(dp[i][j]!=-1) return dp[i][j];
     int ans = 0;
     int dx[] = {0,1};
     int dy[] = {1,0};
     for(int k=0;k<2;k++){
        if(isSafe(i+dx[k] , j+dy[k],m,n)){
           ans += solveMemo(i+dx[k] , j+dy[k] , m , n,dp);

        }
     }
     dp[i][j] =  ans;
     return dp[i][j];
}

// Tabulation 
int solveTab(int m , int n ){
vector<vector<int>>dp(m+1,vector<int>(n+1,0));
  dp[m-1][n-1] = 1;

  for(int i=m-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
     if(i == m-1 && j==n-1) continue;
     int ans = 0;
     int dx[] = {0,1};
     int dy[] = {1,0};
     for(int k=0;k<2;k++){
        if(isSafe(i+dx[k] , j+dy[k],m,n)){
           ans += dp[i+dx[k]][j+dy[k]];
        }
     }
      dp[i][j] = ans;
    }
   
  }
  return dp[0][0];
}

// space optimizatio
int solveSO(int m , int n ){
vector<int>next(n+1,0);
vector<int>curr(n+1,0);
  next[n-1] = 1;

  for(int i=m-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
     if(i == m-1 && j==n-1) {
        curr[j] = 1;
        continue;
     }
     int ans = 0;
     int dx[] = {0,1};
     int dy[] = {1,0};
     for(int k=0;k<2;k++){
        if(isSafe(i+dx[k] , j+dy[k],m,n)){
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




    int uniquePaths(int m, int n) {
        //Recursion 
       // return solveRec(0,0,m,n);

       //Memoization
    //    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    //    return solveMemo(0,0,m,n,dp);

       // Tabulation 
      // return solveTab(m,n);

      //space optimization
      return solveSO(m,n);

    }
};