class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum2 = accumulate(nums.begin(),nums.end(),0LL);
        long long sum1 =0;
        long long count = 0;
        long long n = nums.size();
        for(int i=0 ;i<n-1 ;i++){
            sum1 = sum1 + nums[i];
            sum2 = sum2 - nums[i];
            if(sum1 >= sum2){
                count++;
            }
        }
        return count ;
        
    }
};