class Solution {
public:
// YE SOCHO KI KYA JO SUM DECIDE KIYE HO USE LESS THAN K ME KR SKTE HAI TO FIR K YA USSE BDI ME JAROOR KR SKENGE .
bool possible(int sum ,vector<int>& nums, int k ){

    int n = nums.size();
    int currsum = 0;
    int count = 1;

    for(int i=0;i<n;i++){
        if(nums[i]>sum ) return false;

        if(currsum + nums[i] <= sum){
             currsum += nums[i];
        }
        else{
            count++;
            currsum = nums[i];
        }
        if(count>k) return false;
    }
    return true;
}
    int splitArray(vector<int>& nums, int k) {
        
        int s = *max_element(nums.begin(),nums.end());
        int e = accumulate(nums.begin(),nums.end(),0);

        int ans = 0;
        while(s<=e){

            int sum = s + (e-s)/2;

            if(possible(sum,nums,k)){
                ans = sum;
                e = sum - 1;
            }
            else{
                s = sum + 1;
            }
        }
        return ans;
    }
};