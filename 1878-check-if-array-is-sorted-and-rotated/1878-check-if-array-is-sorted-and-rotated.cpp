class Solution {
public:
    bool issorted(vector<int>&nums,int &ans){
        for(int i=0 ;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                ans = i+1;
                return false;
            }
        }
       return  true;
    }
   
    bool check(vector<int>& nums) {
       vector<int>v(nums.size());
       int ans = 0;
       if(issorted(nums,ans)){
        return true;
       }
       else{
        for(int i= ans ; i<nums.size();i++){
            v.push_back(nums[i]);
        }
        for(int i=0 ;i<ans;i++){
            v.push_back(nums[i]);
        }
        int z = 0;
        if(issorted(v,z)){
            return true;
        }
        else{
            return false;
        }

       }
    }
};