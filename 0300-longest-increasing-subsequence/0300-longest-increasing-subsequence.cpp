class Solution {
public:
//BINARY SEARCH SOLUTION COMPLEXITY O(N*LOG N).
    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp;
        dp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
          if(nums[i]>dp.back()) dp.push_back(nums[i]);
          else{
            auto it = lower_bound(dp.begin(),dp.end(),nums[i]) - dp.begin();
            dp[it] = nums[i];
          }
        }
        return dp.size();
    }
};