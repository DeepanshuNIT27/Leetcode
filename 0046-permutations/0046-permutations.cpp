class Solution {
public:
void permutation( vector<vector<int>>&ans,vector<int>& nums,int index){
    //BASE CASE
    if(index>=nums.size()){
        ans.push_back(nums);
        return ;
    }
    for(int j=index;j<nums.size();j++){
        swap(nums[index],nums[j]);
        permutation(ans,nums,index+1);
         swap(nums[index],nums[j]);
    }

}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        permutation(ans,nums,0);
        return ans;
        
    }
};