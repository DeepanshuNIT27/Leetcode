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

//tabulation
int solveTab(vector<int>& nums,vector<int>&dp, int start , int end){

    for(int i=end ; i>= start ;i--){
         int inc = nums[i] + dp[i+2];
         int exc = 0 + dp[i+1];

         dp[i] = max(inc,exc);
    }
    return dp[start];
}

// space optimization 
int solveSO(vector<int>& nums, int start , int end){
    int prev1 = 0;
    int prev2 = 0;
    int curr ;
    for(int i=end ; i>= start ;i--){
         int inc = nums[i] + prev1;
         int exc = 0 + prev2;

         curr  = max(inc,exc);
         prev1 = prev2;
         prev2 = curr;
    }
    return prev2;
}
    int rob(vector<int>& nums) {
        //Recursion 
        int n = nums.size();
        if(n==1) return nums[0];
        // int ans1 = solveRec(nums,0,n-2);
        // int ans2 = solveRec(nums,1,n-1);
   
       // return max(ans1,ans2);

    //    //Memoization
    //    vector<int>dp1(n+1,-1);
    //    vector<int>dp2(n+1,-1);
    //    int ans1 = solveMemo(nums,0,n-2,dp1);
    //    int ans2 = solveMemo(nums,1,n-1,dp2);

    //    return max(ans1,ans2);

    // Tabulation
    //     vector<int>dp1(n+2,0);
    //    vector<int>dp2(n+2,0);
    //    int ans1 = solveTab(nums,dp1,0,n-2);
    //    int ans2 = solveTab(nums,dp2,1,n-1);

    //    return max(ans1,ans2);

    // space optimization ;

     int ans1 = solveSO(nums,0,n-2);
     int ans2 = solveSO(nums,1,n-1);

       return max(ans1,ans2);
    }
};