class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        vector<int>pre(n,0);
        pre[0] = nums[0];
        int ans = INT_MAX;

        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }

        for(int i=l;i<=r;i++){

            int sum = pre[i-1];
            if(sum>0 && sum<ans){
                ans = sum ;
            }
            int k = i;
            while(k<n){
              
              sum = pre[k] - pre[k-i];
              if(sum>0 && sum<ans){
                ans = sum ;
              }
              k++;
            }
        }
        if(ans != INT_MAX) return ans;
        return -1;
    }
};