class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        
        int prev = nums[0];
        int count = 1;
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]==prev && count<k){
                ans.push_back(nums[i]);
                count++;
            } 

            else if(nums[i]!= prev ){
                prev = nums[i];
                ans.push_back(nums[i]);
                count = 1;
            }
        }
        return ans;
    }
};