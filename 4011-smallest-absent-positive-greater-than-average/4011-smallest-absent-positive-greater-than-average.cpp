class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        float  sum = accumulate(nums.begin(),nums.end(),0LL);
         float  avg =  sum / nums.size();
         sort(nums.begin(),nums.end());
         auto it = upper_bound(nums.begin(),nums.end(),0);
         if(it==nums.end()) return 1;
         int index =  it - nums.begin();
         int first = nums[index];
         
         for(int i = 1;i<=nums.back();i++ ){
            if(count(nums.begin(),nums.end(),i)>0) continue;
            else {
                if(i>avg) return i;
            }
         }
        return nums.back() + 1;
    }
};