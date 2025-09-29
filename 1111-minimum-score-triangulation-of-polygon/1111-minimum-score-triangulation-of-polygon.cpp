class Solution {
public:
int solveMemo(vector<int>&values,int i , int j,vector<vector<int>>&dp){
    //base case
    if(i+1==j) return 0;

    if(dp[i][j]!=-1) return dp[i][j];
  int ans = INT_MAX;
    for(int k=i+1;k<j;k++){
      ans = min(ans,values[i]*values[j]*values[k]+solveMemo(values,i,k,dp)+solveMemo(values,k,j,dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
    
}
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
   return solveMemo(values,0,n-1,dp);
        
    }
};