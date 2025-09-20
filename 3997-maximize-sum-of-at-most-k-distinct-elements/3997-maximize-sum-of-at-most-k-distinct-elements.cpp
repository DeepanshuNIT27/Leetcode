class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>v;
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<n-1;i++){
           if(nums[i]!=nums[i+1] && k>0){
            v.push_back(nums[i]);
            k--;
           }
        }
        if(k) v.push_back(nums[n-1]);
        return v;
    }
};