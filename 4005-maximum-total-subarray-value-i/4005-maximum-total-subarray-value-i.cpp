class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
    long long ans = *max_element(nums.begin(),nums.end())-*min_element(nums.begin(),nums.end());
    return ans*k;
    }
};