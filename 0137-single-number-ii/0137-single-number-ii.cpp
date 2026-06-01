class Solution {
public:
// METHOD-3 BUCKET METHOD 
// 1. AGR VO TWO ME NHI HAI TO ONE ME DALO
//2. AGR VO ONE ME HAI TO USKO TWO ME DALO.
    int singleNumber(vector<int>& nums) {
        
        int one  = 0;
        int two = 0;
        int n = nums.size();

        for(int i=0;i<n;i++){

            one = (nums[i]^one) & ~two ;
            two = (nums[i]^two) & ~one;
        }
        return one;
        
    }
};