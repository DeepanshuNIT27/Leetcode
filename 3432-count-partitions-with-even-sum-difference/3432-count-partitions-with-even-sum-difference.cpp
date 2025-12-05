class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int currsum = 0;
        int count = 0;
        for(int i=0;i<nums.size()-1;i++){
            currsum += nums[i];
            if(abs(currsum - (sum-currsum))%2==0) count++;
        }
        return count;
    }
};