class Solution {
public:
//RECURSIVE SOLUTION
bool solve(vector<int>&nums , int target , int i){
    if(target<0 || i==nums.size()) return false;
    if(target ==0) return true;
    //include 
    bool inc =solve(nums, target-nums[i] ,i+1);
    bool exc = solve( nums ,target , i+1);

    return inc || exc ;
}
//2-D approach 
bool solveMemo(vector<int>&nums , int target , int i, vector<vector<int>>&dp){
    if(target<0 || i==nums.size()) return false;
    if(target ==0) return true;
    //include 
    if(dp[target][i]!= -1) return dp[target][i];
    bool inc =solveMemo(nums, target-nums[i] ,i+1,dp);
    bool exc = solveMemo( nums ,target , i+1,dp);

   dp[target][i] = inc || exc;
   return dp[target][i];
}


    bool canPartition(vector<int>& nums) {
        int n = nums.size();
       int sum = accumulate(nums.begin(),nums.end(),0);
       if((sum%2) !=0) return false;
        int target = sum>>1;
        // recursion 
       // return solve(nums,target ,0);
        // top-downapproach
        int i = 0;
        vector<vector<int>>dp(target+1,vector<int>(n,-1));
        return solveMemo(nums,target,i,dp);
    }
};