class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int mod = 1e9 + 7;
        long long ans = 0LL;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        for(int i=0;i<nums.size();i++){
            int value = nums[i];
            int target = value*2;
            if(mp.find(target)==mp.end()) continue;
         const vector<int>& temp  = mp[target];
            int leftcount = lower_bound(temp.begin(),temp.end(),i) - temp.begin();
            int rightcount = temp.end() - upper_bound(temp.begin(),temp.end(),i);
            ans =( ans + (1LL*leftcount*rightcount)%mod)%mod;
        }
        return (int) ans;
    }
};