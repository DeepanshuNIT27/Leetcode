class Solution {
public:

bool possible(int div ,vector<int>& nums, int threshold){

    int n  = nums.size();
    int res = 0;
    for(int i=0;i<n;i++){
        res += nums[i]/div;
        res += nums[i]%div !=0 ? 1 : 0;

        if(res > threshold) return false;
    }
    return true;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int s = 1;
        int e = *max_element(nums.begin(),nums.end());

        int ans = 0;
        while(s<=e){

            int div = s + (e-s)/2;

            if(possible(div,nums,threshold)) {
                ans = div;
                e = div - 1;
            }
            else{
                 s = div + 1;
            }
        }
        return ans ;
    }
};