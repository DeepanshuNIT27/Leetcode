class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>v(n,-1);

        vector<long long >prefix(n);
        prefix[0] = nums[0];

        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(int i=k; i+k<n ;i++){

            long long sum = prefix[i+k] - (i-k>0 ? prefix[i-k-1] : 0);
            v[i] = sum/(2*k+1);
        }
        return v;
    }
};