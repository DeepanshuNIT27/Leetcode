class Solution {
public:
    void sortColors(vector<int>& nums) {
      int l =0;
      int m=0;
      int h = nums.size()-1;
      while(h>=m){
        if(nums[m]==0){
            swap(nums[m],nums[l]);
            l++;m++;
        }
        else if( nums[m]==1){
            m++;
        }
        else{
            swap(nums[h],nums[m]);
            h--;
        }
      }        
    }
};