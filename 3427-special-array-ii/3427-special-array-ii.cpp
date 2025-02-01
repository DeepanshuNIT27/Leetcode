class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>presum(nums.size(),0);
        for(int i=1 ;i<nums.size();i++){
            presum[i] = presum[i-1];
            if((nums[i-1]%2==0 && nums[i]%2==0) ||(nums[i]%2!=0 && nums[i-1]%2!=0)){
                presum[i] += 1;
            }
        }
        vector<bool>ans;
        for(auto & query : queries){
            int l = query[0];
            int h = query[1];
            if(presum[h]-presum[l]>0){
                ans.push_back(false);
            }
            else{
                ans.push_back(true);
            }
        }
        return ans;
    }
};