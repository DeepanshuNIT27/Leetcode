class Solution {
public:
    int ans = INT_MAX;
   void solveMemo(int i , int j ,int curr ,  vector<vector<int>>& grid , int m , int n ,  vector<vector<vector<bool>>>&dp){

        if(i >= m || j>=n) return;

         curr = curr ^ grid[i][j];
       if(dp[i][j][curr]!=false) return ;
        dp[i][j][curr] = true;
        
        if( i== m-1 && j== n-1){
            ans = min(ans,curr);
        }
       
         
         solveMemo(i,j+1,curr,grid,m,n,dp);
        solveMemo(i+1,j,curr,grid,m,n,dp) ;
    }

  
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
      
        vector<vector<vector<bool>>>dp(m+1,vector<vector<bool>>(n+1,vector<bool>(1024,false)));
         solveMemo(0,0,0,grid,m,n,dp);
        return ans;
    }
};