class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int count1 = 0;
        int count2 = 0;
        int ans = 0;
        if(nums.size()==1){
            return 1;
        }
        for(int i=1 ;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
            count1 ++;
            count2 = 0;
            }
            else if(nums[i]<nums[i-1]){
                count2++;
                count1 = 0;
            }
            else{
                count1 = 0;
                count2 =0;
            }
            ans = max(ans,max(count1,count2));
        }
        return ans+1;
    }
};