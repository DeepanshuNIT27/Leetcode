class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
           vector<int>ans;
           if(nums.size() == 0) return {-1,-1};
           int n = nums.size();
       
        int start = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int upper = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
      
        if( start== n || nums[start]!=target) {
            ans.push_back(-1);
            ans.push_back(-1);
        }
       else{
          ans.push_back(start);
          ans.push_back(upper-1);
       }
       return ans;
    }
};