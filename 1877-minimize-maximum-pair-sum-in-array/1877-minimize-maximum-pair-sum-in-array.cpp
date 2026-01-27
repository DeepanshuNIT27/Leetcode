class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxi = INT_MIN;
        int i = 0;
        int j = nums.size()-1;
        while(i<j){
            maxi = max(maxi , (nums[j]+nums[i]));
            i++;
            j--;
        }
        return maxi;
    }
};