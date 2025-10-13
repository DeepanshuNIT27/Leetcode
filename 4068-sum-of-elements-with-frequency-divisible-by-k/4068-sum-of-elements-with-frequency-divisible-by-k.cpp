class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto&it:nums) mp[it]++;
        int ans = 0;
      for(auto it=mp.begin();it!=mp.end();it++){
        if(it->second %k ==0) ans += it->second * it->first;
      }
        return ans;
    }
};