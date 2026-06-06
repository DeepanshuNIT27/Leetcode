class Solution {
public:
// USE OBSERVATION 
    int search(vector<int>& nums, int target) {
        int  n  = nums.size();
        int  s  = 0;
        int  e  = n-1;

        while(s<=e){

            int mid = s + (e-s)/2;

            if(nums[mid] == target) return mid;

            //left sorted
           if(nums[s]<= nums[mid]){

            if(nums[s]<= target && target<=nums[mid] ) {
                e  = mid-1;
            }
            else {
                 s = mid + 1;
            }
              
           }
           //right sorted
           else{
              if(nums[mid]<=target && target<=nums[e]){
                s = mid+1;
              }
              else {
                e = mid-1;
              }
           }
        }
        return -1;
    }
};