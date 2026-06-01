class Solution {
public:
// BRUTE FORCE METHOD .
// COMPLEXITY O(N*LOGN) AND SPACE O(LOGN);
    vector<int> singleNumber(vector<int>& nums) {
        
        vector<int>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
           if(i+1 < n && nums[i]==nums[i+1]){
               i += 1;
           }
           else if(i+1>=n || nums[i]!=nums[i+1]){
             ans.push_back(nums[i]);
           }
        }
        return ans;
    }
};