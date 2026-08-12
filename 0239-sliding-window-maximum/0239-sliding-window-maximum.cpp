class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int>ans;
        map<int,int>mp;
        int n = nums.size();

        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }

        int d = prev(mp.end())->first;
        ans.push_back(d);

        for(int i=k;i<n;i++){

            mp[nums[i]]++;
            if(mp[nums[i-k]] == 1) {
                mp.erase(nums[i-k]);
            }
            else {
                mp[nums[i-k]]--;
            }

            ans.push_back(prev(mp.end())->first);
        }
        return ans;
        
    }
};