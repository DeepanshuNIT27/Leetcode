class Solution {
public:
// RECURSIVE SOLN
int solveRec(int n, vector<int>&perfect ){
    //Base Case
    if(n==0) return 0;
    if(n<0) return 1e9;
    int ans= 1e9;
    for(int i=0;i<perfect.size();i++){
       if(perfect[i]>n) break;
      ans = min(ans , 1+ solveRec(n-perfect[i],perfect));
    }
    return ans;
}
//MEMOIZATION 
int solveMemo(int n, vector<int>&perfect,vector<int>&dp ){
    //Base Case
    if(n==0) return 0;
    if(n<0) return 1e9;
    if(dp[n]!=-1) return dp[n];
    int ans= 1e9;
    for(int i=0;i<perfect.size();i++){
       if(perfect[i]>n) break;
      ans = min(ans , 1+ solveMemo(n-perfect[i],perfect,dp));
     
    }
     dp[n] = ans;
    return dp[n];
}
// Tabulation Method
int solveTab(int n , vector<int>&perfect){
    vector<int>dp(n+1,0);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
    int ans= 1e9;
    for(int j=0;j<perfect.size();j++){
       if(perfect[j]>i) break;
      ans = min(ans , 1+ dp[i-perfect[j]]);
     
    }
     dp[i] = ans;  
}
     return dp[n];
}


    int numSquares(int n) {
        vector<int>perfect;
        for(int i=1;i*i<=n;i++){
            perfect.push_back(i*i);
        }
        //RECURSION
  //return  solveRec(n,perfect);
     //   Memoization
   //     vector<int>dp(n+1,-1);
   // return solveMemo(n,perfect,dp);

    //Tabulation
    return solveTab(n,perfect);

    }
};