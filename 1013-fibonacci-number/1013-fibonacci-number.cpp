class Solution {
public:
//method-1 recursion
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
 //method-2 using top-down approach
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

 // method-3 using bottom -up approach
 int solveTabulation(int n){
    //step-1 create a dp array
    vector<int>dp(n+1,-1);
    //step-2  base case analyse,copy paste dp update
    if(n==0 || n==1) return n;
    dp[0] =0;
    dp[1] =1;
    //step-3 check parameter range ,reverse it , and run a loop over it
  //  recursion->n->0;
// reverse->0->n
for(int i=2;i<=n ;i++){
    dp[i] = dp[i-1] + dp[i-2];
}
return dp[n];
 }
 //METHOD-4 
 //SPACE OPTIMIZATION
 int solvespaceOpti(int n){

 if(n==0 || n==1) return n;
 int prev = 0;
 int curr = 1;
  int ans ;
for(int i=2;i<=n ;i++){
   ans = prev + curr;
   prev = curr;
   curr = ans;
}
return curr;
 }

    int fib(int n) {
 //top-down approach
//step-1 create a DP array here 1d dp will used
// vector<int>dp(n+1,-1);
// return solveMemo(n,dp);

//bottom -up approach
//  return solveTabulation(n);

//SPACE OPTIMIZATION
return solvespaceOpti(n);
    }
};