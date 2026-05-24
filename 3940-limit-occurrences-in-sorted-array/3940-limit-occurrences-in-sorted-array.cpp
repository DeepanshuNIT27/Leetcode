class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto&it:nums) mp[it]++;
        vector<int>ans;

        for(auto&it:mp){
            it.second = min(it.second,k);
        }
        for(int i=0;i<nums.size();i++){

            if(mp[nums[i]]!=0) {ans.push_back(nums[i]) ; mp[nums[i]]--;}

        }
        return ans ;
    }
};