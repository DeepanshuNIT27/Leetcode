class Solution {
public:
//recursion
int  solveRec(int n){
    if(n==0) return 1;
    if(n<0) return 0;
   int ans1 =  solveRec(n-1);
   int ans2 =  solveRec(n-2);

   return ans1+ans2;
}

//Memoization
int solveMemo(int n , vector<int>&dp ){

     if(n==0) return 1;
    if(n<0) return 0;
  if(dp[n]!=-1) return dp[n];
   int ans1 =  solveMemo(n-1,dp);
   int ans2 =  solveMemo(n-2,dp);

   dp[n] = ans1 + ans2 ;
   return dp[n];
}

// tabulation 
int solveTab(int n ){
    vector<int>dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2;i<=n;i++){
       int ans1 = dp[i-1];
       int ans2 = dp[i-2] ;
       dp[i] = ans1 + ans2;
    }
    return dp[n];

}
    int climbStairs(int n) {
      
       // return solveRec(n);

      // vector<int>dp(n+1,-1);
      // return solveMemo(n,dp);
      return solveTab(n);
    }
};