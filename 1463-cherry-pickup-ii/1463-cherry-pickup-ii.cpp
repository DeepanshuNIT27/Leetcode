class Solution {
public:
//RECURSION 
int solveRec(int i, int j1 , int j2,int n , int m ,vector<vector<int>>& grid){

    if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e8;
    if(i == n) return 0;

    int maxi = -1e8;
    for(int dj2 =-1; dj2<=1 ; dj2++){
     for(int dj1=-1;dj1<=1 ; dj1++){

        if(j1 == j2) {
            int ans  =  grid[i][j1] + solveRec(i+1,j1+dj1 , j2+dj2,n,m,grid);
            maxi = max(ans,maxi); 
        }
        else{
            int ans = grid[i][j1] + grid[i][j2] + solveRec(i+1,j1+dj1 , j2+dj2,n,m,grid);
             maxi = max(ans,maxi); 
        }
     }
    }
    return maxi;
}
//MEMOIZATION 
int solveMemo(int i, int j1 , int j2,int n , int m ,vector<vector<int>>& grid,  vector<vector<vector<int>>>&dp){

    if(j1<0 || j1>=m || j2<0 || j2>=m) return -1e8;
    if(i == n) return dp[i][j1][j2] = 0;
    if(dp[i][j1][j2] !=-1) return dp[i][j1][j2];
    int maxi = -1e8;
    for(int dj2 =-1; dj2<=1 ; dj2++){
     for(int dj1=-1;dj1<=1 ; dj1++){

        if(j1 == j2) {
            int ans  =  grid[i][j1] + solveMemo(i+1,j1+dj1 , j2+dj2,n,m,grid,dp);
            maxi = max(ans,maxi); 
        }
        else{
            int ans = grid[i][j1] + grid[i][j2] + solveMemo(i+1,j1+dj1 , j2+dj2,n,m,grid,dp);
             maxi = max(ans,maxi); 
        }
     }
    }
    return  dp[i][j1][j2] = maxi;
}


    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //RECURSION 
      //  return solveRec(0,0,m-1,n,m,grid);

      //MEMOIZATION 
      vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
      return solveMemo(0,0,m-1,n,m,grid,dp);
    }
};