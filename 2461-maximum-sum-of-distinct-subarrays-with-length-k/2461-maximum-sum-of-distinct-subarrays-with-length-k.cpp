class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxi = 0LL;
        long long sum = 0LL;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
         
          sum += nums[i];
          mp[nums[i]] ++ ;

          if(mp.size() == k){
            maxi = max(maxi,sum);
          }

          if(i>=k-1){
            if(mp[nums[i-k+1]]>1) mp[nums[i-k+1]]--;
            else mp.erase(nums[i-k+1]);

            sum -= nums[i-k+1];
          }  
        }
        return maxi;
    }
};