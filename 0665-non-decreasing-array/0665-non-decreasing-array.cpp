class Solution {
public:
bool issorted(vector<int>&nums){
    for(int i=0 ;i< nums.size()-1;i++){
        if(nums[i+1]<nums[i]){
            return false;
        }
    }
    return true;
}
    bool checkPossibility(vector<int>& nums) {
        for(int i=0 ;i<nums.size()-1 ;i++){
            if(nums[i]>nums[i+1]){
                if(i>0 && nums[i-1]>nums[i+1]){
                    nums[i+1] = nums[i];
                }
                else{
                    nums[i] = nums[i+1];
                }
                break;
       }
        }
        return issorted(nums);
        
    }
};