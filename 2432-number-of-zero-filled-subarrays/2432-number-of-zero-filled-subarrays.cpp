class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }
            else {
                long long d = (count*(count+1))/2;
                sum += d;
                count = 0;
            }
        }
        sum +=  (count*(count+1))/2;
        return sum;
    }
};