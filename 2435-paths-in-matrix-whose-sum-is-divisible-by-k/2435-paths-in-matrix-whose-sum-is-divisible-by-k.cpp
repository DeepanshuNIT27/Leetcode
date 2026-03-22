class Solution {
public:
const int mod = 1e9+7;
//Recursion 
int solveRec(int i , int j , int sum ,vector<vector<int>>& grid,int k , int n , int m){

  if(i>=n || j>=m) return 0;
  
  sum += grid[i][j];
 if(i==n-1 && j==m-1){
    if(sum%k == 0) return 1;
 }

 int right = solveRec(i,j+1,sum,grid,k,n,m);
 int left = solveRec(i+1,j,sum,grid,k,n,m);

 return (left + right)%mod;
}

// Memoization 
int solveMemo(int i , int j , int sum ,vector<vector<int>>& grid,int k , int n , int m,vector<vector<vector<int>>>&dp){

  if(i>=n || j>=m) return 0;
  
  sum  =  (sum + grid[i][j])%k;
 if(i==n-1 && j==m-1){
    return sum%k== 0 ? 1 : 0;
 }
 if(dp[i][j][sum]!=-1) return dp[i][j][sum];

 int right = solveMemo(i,j+1,sum,grid,k,n,m,dp);
 int left = solveMemo(i+1,j,sum,grid,k,n,m,dp);

 dp[i][j][sum] =  (left + right)%mod;
 return  dp[i][j][sum] ;
}

//Tabulation 
void solveTab(vector<vector<int>>& grid, int p){
    int  n = grid.size();
    int  m = grid[0].size();

    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(p+1,-1)));
    dp[n-1][m-1][0] = 1;

    // for(int i=n-1;i>=0;i--){
    //     for(int j=m-1;j>=0;j--){
    //         for(int k=p;k>=0;k--){

    //             int right = dp[i][j+1][sum];
    //             int left = dp[i+1][j][sum];

    //            dp[i][j][sum] =  (left + right)%mod;
    //         }
    //     }
    // }

}





    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int  n = grid.size();
        int  m = grid[0].size();

        //Recursion 
        // int ans = solveRec(0,0,0,grid,k,n,m);
        // return ans%mod;

        //Memoization 
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        int ans = solveMemo(0,0,0,grid,k,n,m,dp);
        return ans%mod;

        //Tabulation 


    }
};