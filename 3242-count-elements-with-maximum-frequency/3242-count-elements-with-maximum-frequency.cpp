class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>v(102,0);
        for(int i=0;i<nums.size();i++){
            v[nums[i]] += 1;
        }
    int maxi = *max_element(v.begin(),v.end());
    int ans = 0;
    for(auto i:v) {
        if(i==maxi) ans+= maxi;
    }
    return ans;
    }

};