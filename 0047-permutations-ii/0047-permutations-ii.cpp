class Solution {
public:
void PermtationTwo( vector<vector<int>>&ans,vector<int>& nums,int index){
    //BASE CASE
    if(index>=nums.size()){
        ans.push_back(nums);
        return ;
    }

    for(int j=index;j<nums.size();j++){
        swap(nums[index],nums[j]);
        PermtationTwo(ans,nums,index+1);
        swap(nums[index],nums[j]);
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
      PermtationTwo(ans,nums,0);
        set<vector<int>>st;
        for(auto&it:ans) st.insert(it);
        ans.clear();
        for(auto&s:st) ans.push_back(s);
        return ans;
    }
};