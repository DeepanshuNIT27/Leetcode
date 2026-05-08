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

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        //RECURSION 
        // int ans =  solveRec(0,target,nums);
        // if(ans==INT_MIN) return -1;
        // return ans;

        //MEMOIZATION
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        int ans = solveMemo(0,target,nums,dp);
        if(ans==INT_MIN) return -1;
        return ans;
    }
};