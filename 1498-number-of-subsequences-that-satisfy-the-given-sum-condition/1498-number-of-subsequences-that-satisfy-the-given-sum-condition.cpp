class Solution {
public:
//OPTIMAL APPROACH OBSERVATION
//COMPLEXITY O(N*LOGN ) TIME AND O(N) SPACE

const int mod = 1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>power(n);
        power[0] = 1;
        for(int i=1;i<n;i++){
             power[i] = (power[i-1] *2LL)%mod;
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        long long ans = 0LL;

        while(i<=j){
            
            if(nums[i] + nums[j] > target){
                j--;
            }
            else{
                ans =  (ans + power[j-i])%mod;
                i++;
            }
        }
          return (int)ans;

    }
};