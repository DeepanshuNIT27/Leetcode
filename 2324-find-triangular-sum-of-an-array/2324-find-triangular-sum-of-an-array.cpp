class Solution {
public:
    int triangularSum(vector<int>& nums) {
        while(nums.size()!=0){
            vector<int>b;
            for(int i=0;i<nums.size()-1;i++){
                int ans = (nums[i]+ nums[i+1])%10;
                b.push_back(ans);
            }
            nums = b;
        }
        return nums[0];
    }
};