class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int>mp;
        int i=0;
        int j= 0;
        while(j<n){
            if(nums[j]==1){
                j++;
            }
            else if(nums[j]==0 && mp.size()==0){
                mp[nums[j]] = j;
                j++;
        }
            else{
                ans = max(ans,(j-i-1));
                i = mp[0];
                    i++;
                    mp[0] = j;
                    j++;
                }
            }
        
          int d = n-i-1;
       ans = max(ans,d);
        return ans;
    }
};