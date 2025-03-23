class Solution {
public:
//solved using recursion
  int solvebyRecursion(int n){
//base case
    if(n==0 || n==1){
        return n;
    }
    int ans = solvebyRecursion(n-1) + solvebyRecursion(n-2);
    return ans;
 }

 //solved using DP
 int solveMemo(int n,vector<int>&dp){
    if(n==0 || n==1) return n;
// step-3 - if ans exist no need to solve again just return the ans
if(dp[n]!=-1){
    return dp[n];
}
    //step-2 store the ans and return 
    dp[n] =solveMemo(n-1,dp) + solveMemo(n-2,dp);
    return dp[n];
 }
    int fib(int n) {
 //top-down approach
//step-1 create a DP array here 1d dp will used
vector<int>dp(n+1,-1);
return solveMemo(n,dp);
    }
};