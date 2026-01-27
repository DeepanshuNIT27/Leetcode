class Solution {
public:

    int minimumDifference(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i+k-1<n){
                mini = min(mini , nums[i+k-1]-nums[i]);
            }
        }
        return mini;
    }
};