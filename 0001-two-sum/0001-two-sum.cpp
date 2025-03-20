class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mp;
      
      for(int i=0;i<nums.size();i++){
        int curr = nums[i];
        int required = target - nums[i];
        if(mp.find(required) != mp.end()){
            ans.push_back(i);
            ans.push_back(mp[required]);
            break;
        }
         mp[curr] = i;
      }
      return ans;
    }
};