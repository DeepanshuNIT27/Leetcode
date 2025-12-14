class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i=0;i<k;i++){
            sum += nums[i];
        }
        int sum1 = 0;
        int n = nums.size();
       while(k){
        sum1 += nums[n-1];
        n--;
        k--;
       }
       return sum1-sum;
    }
};