class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        long long ans = INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
             
             long long a = 1LL*nums[i]*nums[j];
             long long b = __gcd(nums[i],nums[j]);

             long long temp =  a / (1LL*b*b);
             ans = max(ans,temp);
            }
        }
        return ans;

    }
};