class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        long long maxi = 0LL;
        long long sum = 0 ;
        for(int i=0;i<n;i++){

            sum += nums[i];
            mp[nums[i]]++;

            if(i>=k-1 && mp.size()>=m){
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