class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        long long count = 0LL;
        long long z = LONG_LONG_MAX;
        long long x  = nums2.back();
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]>=nums2[i]){
                count += nums1[i] - nums2[i];
                if(x<=nums1[i] && x>=nums2[i]) z= 0;
                else {
                    z = min(z,min(abs(x-nums1[i]), abs(x-nums2[i])));
                }
            }
            else{
                count += nums2[i] - nums1[i];
                 if(x>=nums1[i] && x<=nums2[i]) z= 0;
                 else {
                   z = min(z,min(abs(x-nums1[i]), abs(x-nums2[i])));  
                 }
            }
        }
        count += z+1;
        return count;

    }
};