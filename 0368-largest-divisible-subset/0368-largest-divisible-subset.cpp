class Solution {
public:
//QUE KO DECODE KRO YE LIS HI HAI .
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>parent(n);
        int idx = 0;
        int maxi = 0;

        for(int i=0;i<n;i++){
            parent[i] = i;
            for(int prev=0;prev<i;prev++){

                if(nums[i]%nums[prev]==0  && dp[prev] + 1 >dp[i]){

                    dp[i] = dp[prev] + 1 ;
                    parent[i] = prev;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                idx = i;
            }

        }
        vector<int>ans;
        ans.push_back(nums[idx]);
        while(parent[idx] != idx){
            idx = parent[idx];
            ans.push_back(nums[idx]);
        }
        reverse(ans.begin(),ans.end());
        return ans ;
    }
};