class Solution {
public:
//REcursion ka code
//  int solve(vector<int>&nums, int prevIndex , int i){
//     //base case
//     if(i>= nums.size()){
//         return 0;
//     }
//     //include
//     int incl = 0;
//     if(prevIndex == -1 || nums[i]> nums[prevIndex]){
//         incl = 1 + solve(nums,i,i+1);
//     }
//     //exclude
//     int excl = 0 + solve(nums,prevIndex,i+1);
//     int ans = max(incl,excl);
//     return ans;

//  }
// 2d .dp
int solveMemo(vector<int>&nums, int lastIndex , int i,vector<vector<int>>&dp){
    //base case
    if(i>= nums.size()){
        return 0;
    }
    //include
    if(dp[lastIndex+1][i] != -1) return dp[lastIndex+1][i];
    int incl = 0;
    if(lastIndex == -1 || nums[i]> nums[lastIndex]){
        incl = 1 + solveMemo(nums,i,i+1,dp);
    }
    //exclude
    int excl = 0 + solveMemo(nums,lastIndex,i+1,dp);
    dp[lastIndex+1][i] = max(incl,excl);
    return dp[lastIndex+1][i];

 }
    int lengthOfLIS(vector<int>& nums) {
        int lastIndex = -1;
    //   return   solve(nums,prevIndex,0);
    //2d dp
    int n = nums.size();
vector<vector<int>>dp(n+2 ,vector<int>(n+1,-1));
 return    solveMemo(nums,lastIndex,0,dp);
    }
};