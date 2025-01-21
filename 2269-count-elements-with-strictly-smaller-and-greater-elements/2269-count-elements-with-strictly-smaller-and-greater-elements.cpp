class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int count = 0;
        for(int i=1 ;i<nums.size()-1;i++){
            if(nums[0]==nums[i]){
                count++;
            }
            if(nums[nums.size()-1]== nums[i]){
                count++;
            }
        }
        if(nums[0]== nums[nums.size()-1]){
            return 0;
        }
        else if(nums[0]== nums[nums.size()-2]){
            return 0;
        }
        else{ 
            return nums.size()-2-count;
        
    }
    return -1;
    }
};