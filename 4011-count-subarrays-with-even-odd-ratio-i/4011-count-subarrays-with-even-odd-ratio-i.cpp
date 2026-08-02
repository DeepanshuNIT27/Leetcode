class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n  = nums.size();

        vector<int>eve(n,0);
        if(nums[0]&1) eve[0] = 0;
        else eve[0] = 1;
        
        for(int i=1;i<n;i++){
           if(nums[i] %2==0) {
               eve[i] = eve[i-1] + 1;
           }
           else {
            eve[i] = eve[i-1];
           }
        }
        int count = 0;

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
              
             int even = i >0 ? eve[j] - eve[i-1] : eve[j];
             int odd =  j-i + 1 - even;

           if(odd>0 && (even*b <= odd*a)){
            count++;
           }

            }
        }
        return count;
    }
};