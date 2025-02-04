class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = INT_MIN;
        int sum = nums[0];
        for(int i=1 ;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                sum = sum + nums[i];
            }
            else{
                ans = max(ans,sum);
                sum = nums[i];
            }
        }
        ans = max(ans,sum);
        int maxelement = *max_element(nums.begin(),nums.end());
       return max(ans,maxelement);
    }

};