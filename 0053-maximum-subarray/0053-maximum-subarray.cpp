class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<long long >pre(n);
        pre[0] = nums[0];
        for(int i=1;i<n;i++) {
            pre[i] = pre[i-1] +nums[i];
        }
        long long bestOfMin = 0LL;
        long long ans = -1e18;
        for(int i=0;i<n;i++){
            long long best = pre[i] - bestOfMin;
            bestOfMin = min(bestOfMin, pre[i]);
            ans = max(ans,best);
        }
        return ans;
    }
};