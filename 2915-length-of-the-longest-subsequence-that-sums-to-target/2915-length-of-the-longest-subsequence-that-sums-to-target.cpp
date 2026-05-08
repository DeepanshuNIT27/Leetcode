class Solution {
public:
//RECURSION
int solveRec(int i , int target , vector<int>& nums ){

    if(target<0) return INT_MIN;
 
     if(i>=nums.size()){
        if(target == 0) return 0;
        else return INT_MIN;
     }

     int inc = solveRec(i+1,target-nums[i],nums);
     if(inc!=INT_MIN) inc += 1;
     int exc = solveRec(i+1,target,nums);

     return max(inc,exc);
}

//MEMOIZATION 
int solveMemo(int i , int target , vector<int>& nums, vector<vector<int>>&dp ){

    if(target<0) return INT_MIN;
 
     if(i>=nums.size()){
        if(target == 0) return 0;
        else return INT_MIN;
     }
     if(dp[i][target]!=-1) return dp[i][target];

     int inc = solveMemo(i+1,target-nums[i],nums,dp);
     if(inc!=INT_MIN) inc += 1;
     int exc = solveMemo(i+1,target,nums,dp);

     return  dp[i][target] = max(inc,exc);
}

// TABULATION 
int solveTab(int target , vector<int>&nums){
    int n = nums.size();
    vector<vector<int>>dp(n+1, vector<int>(target+1 , INT_MIN));
    dp[n][0] = 0;

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=target;j++){
            int inc = INT_MIN;
            if(j-nums[i]>=0) inc = dp[i+1][j-nums[i]];
             if(inc!=INT_MIN) inc += 1;
             int exc = dp[i+1][j];

             dp[i][j] = max(inc,exc);

        }
    }
 return dp[0][target];
}

// SPACE OPTIMIZATION 

int solveSO(int target , vector<int>&nums){
    int n = nums.size();
   vector<int>curr(target+1,INT_MIN);
   vector<int>next(target+1,INT_MIN);
    next[0] = 0;

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<=target;j++){
            int inc = INT_MIN;
            if(j-nums[i]>=0) inc = next[j-nums[i]];
             if(inc!=INT_MIN) inc += 1;
             int exc = next[j];

             curr[j] = max(inc,exc);

        }
        next = curr;
    }
 return next[target];
}



    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        //RECURSION 
        // int ans =  solveRec(0,target,nums);
        // if(ans==INT_MIN) return -1;
        // return ans;

        //MEMOIZATION
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // int ans = solveMemo(0,target,nums,dp);
        // if(ans==INT_MIN) return -1;
        // return ans;

        //TABULATION 
        // int ans = solveTab(target,nums);
        // if(ans==INT_MIN) return -1;
        // return ans;

        //SPACE OPTIMIZATION
        int ans = solveSO(target,nums);
        if(ans==INT_MIN) return -1;
        return ans;

    }
};