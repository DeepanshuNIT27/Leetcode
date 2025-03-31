class Solution {
public:
//recursive code
long long int mod = 1e9+7;
int solveRec(int n ,int k ,int target){
    //base case
    if(target <0 || n<0) return 0;
    if(n==0 && target ==0) return 1;
    if(n==0 && target!=0) return 0;
    if(n!=0 && target ==0) return 0;
    //1.case hm smbhalenge
    int ans = 0;
    for(int i=1;i<=k;i++){
        ans += solveRec(n-1,k,target-i);
    }
    return ans;
}
//memo
int solveMemo(int n ,int k ,int target,vector<vector< long long int>>&dp){
    //base case
    if(target <0 || n<0) return 0;
    if(n==0 && target ==0) return 1;
    if(n==0 && target!=0) return 0;
    if(n!=0 && target ==0) return 0;
    //1.case hm smbhalenge
    if(dp[n][target]!=-1) return dp[n][target];
   long long int ans = 0;
    for(int i=1;i<=k;i++){
        ans += solveMemo(n-1,k,target-i,dp);
    }
    dp[n][target] = ans%mod;
    return dp[n][target];
}

//tabulation 
int solveTebu(int n ,int k ,int target){
     vector<vector<long long int>>dp(n+2,vector< long long int>(target+2,0));
      dp[0][0] = 1;
    
    for(int N =1; N<=n ;N++){
        for(int t =1; t<=target ;t++){
             long long int ans = 0;
         for(int i=1;i<=k;i++){
             if(t-i>=0){
            ans += dp[N-1][t-i];
           }
          }
         dp[N][t] = ans%mod;
         }
    }
    return dp[n][target];
      
}
    int numRollsToTarget(int n, int k, int target) {
        //recursive 
        // return solveRec(n,k,target);

        //memo
        // vector<vector<long long int>>dp(n+1,vector< long long int>(target+1,-1));
        // return solveMemo(n,k,target,dp);
        
        //tabulation
       return solveTebu(n,k,target);
    }
};