class Solution {
public:
//Recursison 
int solveRec(vector<int>& nums,int i , int n){
    if(i>n) return 0;

    int inc = nums[i] + solveRec(nums,i+2,n);
    int exc = 0 + solveRec(nums,i+1,n);

    return max(inc,exc);
}

// Memoization
int solveMemo(vector<int>& nums,int i , int n, vector<int>&dp){
    if(i>n) return 0;
  if(dp[i]!=-1) return dp[i];
    int inc = nums[i] + solveMemo(nums,i+2,n,dp);
    int exc = 0 + solveMemo(nums,i+1,n,dp);

    dp[i] =  max(inc,exc);
    return dp[i];
}
    int rob(vector<int>& nums) {
        //Recursion 
        int n = nums.size();
        if(n==1) return nums[0];
        // int ans1 = solveRec(nums,0,n-2);
        // int ans2 = solveRec(nums,1,n-1);
   
       // return max(ans1,ans2);

       //Memoization
       vector<int>dp1(n+1,-1);
       vector<int>dp2(n+1,-1);
       int ans1 = solveMemo(nums,0,n-2,dp1);
       int ans2 = solveMemo(nums,1,n-1,dp2);

       return max(ans1,ans2);
       
    }
};