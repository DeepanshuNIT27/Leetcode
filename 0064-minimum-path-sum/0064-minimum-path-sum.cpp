class Solution {
public:
//Recursion
int solveRec(int i, int j ,vector<vector<int>>& grid, int n , int m ){

    if(i==n-1 && j==m-1) return grid[i][j];

    if(i>=n || j>=m) return INT_MAX;

    int right = solveRec(i,j+1,grid,n,m);
    int left = solveRec(i+1,j,grid,n,m);

    return grid[i][j] + min(right,left);
}
//Memoization 
int solveMemo(int i, int j ,vector<vector<int>>& grid, int n , int m , vector<vector<int>>&dp){

    if(i==n-1 && j==m-1) return grid[i][j];

    if(i>=n || j>=m) return INT_MAX;

    if(dp[i][j]!=-1) return dp[i][j];

    int right = solveMemo(i,j+1,grid,n,m,dp);
    int left = solveMemo(i+1,j,grid,n,m,dp);

    dp[i][j] =  grid[i][j] + min(right,left);
    return dp[i][j] ;
}


    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //Recursion
        //return solveRec(0,0,grid,n,m);

        //Memoization
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solveMemo(0,0,grid,n,m,dp);
    }
};