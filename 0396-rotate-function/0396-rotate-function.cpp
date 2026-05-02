class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n =nums.size();

        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<int>v(n,0) ;
        int temp = 0;
        for(int i=0;i<n;i++){
           temp += nums[i] * i;
        }

        v[0] = temp;
        for(int k=1;k<n;k++){

            int ans = v[k-1] + sum - (n*nums[n-k]);
            v[k] = ans;
        }
        int maxi = *max_element(v.begin(),v.end());
        return maxi;
    }
};