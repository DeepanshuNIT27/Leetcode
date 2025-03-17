class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &num:nums) mp[num]++;
        if(mp.size()> nums.size()) return false;
        else{
            for(auto & ans:mp){
                if(ans.second%2!=0) return false;
            }
        }
        return true;
    }
};