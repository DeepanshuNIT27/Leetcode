class Solution {
public:
    int maxSum(vector<int>& nums) {
       int maxelement = *max_element(nums.begin(),nums.end());
       set<int>s;
       int ans = 0;
       if(maxelement<0){
        return maxelement;
       }
       else{
       for(auto it:nums){
        if(it>0) s.insert(it);
       }
       ans = accumulate(s.begin(),s.end(),0);
      
       }
        return ans;
    }
};