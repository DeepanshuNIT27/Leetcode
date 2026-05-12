class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        int i = 0;
        int j = 0;
        int n = nums.size();
        long long sum = 0LL;
        long long score = 0LL;
        long long ans = 0LL;

        while(j<n){

            sum += nums[j];
            score = sum*1LL*(j-i+1);
 
            while(score>=k && i<=j){
             
              sum -= nums[i];
              i++;
            score = sum*1LL*(j-i+1);
              
            }

            ans += (j-i+1);
            j++;
        }
        return ans ;
    }
};