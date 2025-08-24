class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int maxig = nums.size()/k;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second>maxig){
                return false;
            }
        }
        return (n%k==0);
    }
};