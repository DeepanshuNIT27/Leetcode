class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        vector<int>v;
        for(int i=0 ;i<nums.size()-1 ;i++){
            if(nums[i]== nums[i+1]){
                nums[i] = 2*nums[i];
                nums[i+1] = 0;
            }
        }
        int count = 0;
        for(auto &it:nums){
            if(it==0) count++;
            if(it!=0){
                v.push_back(it);
            }
        }
        while(count){
            v.push_back(0);
            count--;
        }
return v;
    }
};