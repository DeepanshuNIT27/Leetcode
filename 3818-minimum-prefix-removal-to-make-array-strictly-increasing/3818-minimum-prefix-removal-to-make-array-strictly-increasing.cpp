class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for(int i=n-2;i>=0;i--){
              if(nums[i]>=nums[i+1]){
                ans = i;
                break;
              }
        }
       return ans+1;
    }
};