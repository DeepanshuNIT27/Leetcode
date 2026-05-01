class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        vector<int>pre(n,0);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
             int d = pre[j] - (i-1>=0 ? pre[i-1] : 0);
             if(d==k) count++;
            }
        }
        return count;
    }
};