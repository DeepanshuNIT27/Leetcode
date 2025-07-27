class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        long long ans = 0;
         int z = nums.size()/3;
    
        sort(nums.rbegin(),nums.rend());
      int i = 1;
      while(z){
        ans += nums[i];
        i += 2;
        z--;
      }
       return ans;
    }
};